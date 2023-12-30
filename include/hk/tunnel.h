#ifndef HK_TUNNEL_H
#define HK_TUNNEL_H

#include <functional>
#include <stdexcept>

namespace hk::signals {
// class tunnel_not_connected : public std::runtime_error {};

template <typename Return, typename... Args>
class Tunnel {
 public:
  /** Slots can take arguements and also return */
  using Slot = std::function<Return(Args...)>;

 public:
  /** Default constructed */
  Tunnel() = default;

  /** Cannot be copied */
  Tunnel(const Tunnel&) = delete;

  /** Can be moved */
  Tunnel(Tunnel&&) noexcept = default;

 public:
  auto is_connected() const -> bool { return bool(tunnel); }

  template <typename Lambda>
  auto connect(Lambda slot) -> void {
    tunnel = slot;
  }

  auto disconnect() -> void { tunnel = nullptr; }

  auto emit(Args... args) -> Return {
    if (tunnel == nullptr) {
      throw std::runtime_error("Tunnel not connected");
    }

    return tunnel(args...);
  }

  auto operator()(Args... args) -> Return { return emit(args...); }

 private:
  Slot tunnel = nullptr;
};

template <typename Lambda, typename Return, typename... Args>
auto connect(Tunnel<Return, Args...>& tunnel, Lambda slot) -> void {
  tunnel.connect(slot);
}

template <typename Return, typename... Args>
auto disconnect(Tunnel<Return, Args...>& tunnel) -> void {
  tunnel.disconnect();
}
}  // namespace hk::signals

#endif
