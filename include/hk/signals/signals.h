#include <functional>
#include <tuple>

namespace hk {
template <typename... T>
class Signal {
private:
  /** Slots can take arguements but don't return anything */
  using slot_func = std::function<void(T...)>;
  using slot_idx = std::size_t;

  std::vector<slot_func> slots;

public:
  /** Default constructed */
  Signal() = default;

  /** Cannot be copied */
  Signal(const Signal&) = delete;
  Signal& operator=(const Signal&) = delete;

  auto emit(T... args) -> void {
    for (auto& slot: slots) {
      auto slot_with_args = std::bind(slot, args...);
      slot_with_args();
    }
  }

  auto operator() (T... args) -> void {
    return emit(args...);
  }

  auto connect(const slot_func& slot) -> slot_idx {
    auto connection_id = slots.size();
    slots.push_back(slot);
    return connection_id;
  }

  template<typename Mem, typename Obj>
  auto connect(Mem member, Obj& object) -> slot_idx {
    auto member_func = slot_func{ std::bind_front(member, &object) };

    return connect(member_func);
  }
};
}