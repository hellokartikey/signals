#ifndef HK_SIGNAL_H
#define HK_SIGNAL_H

#include <algorithm>
#include <functional>
#include <map>

namespace hk::signals {
/** Connection IDs */
using Index = std::size_t;

template <typename... Args>
class Signal {
 public:
  /** Slots can take arguements but don't return anything */
  using Slot = std::function<void(Args...)>;

 public:
  /** Default constructed */
  Signal() = default;

  /** Cannot be copied */
  Signal(const Signal&) = delete;

  /** Can be moved */
  Signal(Signal&&) noexcept = default;

 public:  // API
  auto connections() const -> Index { return slots.size(); }

  template <typename Lambda>
  auto connect(Lambda slot) -> Index {
    slots[curr_idx] = Slot{slot};
    return curr_idx++;
  }

  auto disconnect(Index idx) -> void { slots.erase(idx); }

  auto emit(Args... args) -> void {
    std::ranges::for_each(slots, [&](const auto& val) {
      auto& [idx, slot] = val;
      slot(args...);
    });
  }

  auto operator()(Args... args) -> void { return emit(args...); }

 private:
  std::map<Index, Slot> slots;
  Index curr_idx = 0;
};

template <typename Lambda, typename... Args>
auto connect(Signal<Args...>& signal, Lambda fun) -> Index {
  return signal.connect(fun);
}

template <typename... Args>
auto disconnect(Signal<Args...>& signal, Index idx) -> void {
  signal.disconnect(idx);
}
}  // namespace hk::signals

#endif
