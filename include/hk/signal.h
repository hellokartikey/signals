#ifndef HK_SIGNALS_H
#define HK_SIGNALS_H

#include <algorithm>
#include <functional>
#include <map>

namespace hk::signals {
template <typename... T>
class Signal {
 public:
  /** Connection IDs */
  using slot_idx = std::size_t;

  /** Slots can take arguements but don't return anything */
  using slot_fun = std::function<void(T...)>;

 public:
  /** Default constructed */
  Signal() = default;

  /** Cannot be copied */
  Signal(const Signal&) = delete;

  /** Can be moved */
  Signal(Signal&&) noexcept = default;

  auto connections() const -> slot_idx { return slots.size(); }

  auto emit(T... args) -> void {
    std::ranges::for_each(slots, [&](const auto& val) {
      auto& [idx, slot] = val;
      slot(args...);
    });
  }

  auto operator()(T... args) -> void { return emit(args...); }

  template <typename Lambda>
  auto connect(Lambda slot) -> slot_idx {
    slots[curr_idx] = slot_fun{slot};
    return curr_idx++;
  }

  auto disconnect(slot_idx idx) -> void { slots.erase(idx); }

 private:
  std::map<slot_idx, slot_fun> slots;
  slot_idx curr_idx = 0;
};

template <typename Lambda, typename... T>
auto connect(Signal<T...>& signal, Lambda fun) -> std::size_t {
  auto fun_obj = std::function<void(T...)>{fun};
  return signal.connect(fun_obj);
}

template <typename... T>
auto disconnect(Signal<T...>& signal, std::size_t idx) -> void {
  signal.disconnect(idx);
}
}  // namespace hk::signals

#endif