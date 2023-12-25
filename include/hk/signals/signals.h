#include <functional>
#include <map>

namespace hk {
template <typename... T>
class Signal {
private:
  /** Slots can take arguements but don't return anything */
  using slot_func = std::function<void(T...)>;
  using slot_ptr = void (*) (T...);

  using slot_idx = std::size_t;

  // std::map<slot_idx, slot_func> slots;
  std::vector<slot_func> slots;
  slot_idx curr_idx = 0;

private:
  auto connect_obj(const slot_func& slot_obj) -> slot_idx {
    auto connection_id = connections();
    slots.push_back(slot_obj);
    return connection_id;
  }

public:
  /** Default constructed */
  Signal() = default;

  /** Cannot be copied */
  Signal(const Signal&) = delete;
  Signal& operator=(const Signal&) = delete;

  auto connections() const -> slot_idx {
    return slots.size();
  }

  auto emit(T... args) -> void {
    for (auto& slot: slots) {
      auto slot_with_args = std::bind(slot, args...);
      slot_with_args();
    }
  }

  auto operator() (T... args) -> void {
    return emit(args...);
  }

  auto connect(const slot_ptr& slot) -> slot_idx {
    auto slot_obj = slot_func{slot};
    return connect_obj(slot_obj);
  }

  template<typename Member, typename Object>
  auto connect(const Member member, Object& object) -> slot_idx {
    auto slot_obj = slot_func{std::bind_front(member, &object)};
    return connect_obj(slot_obj);
  }
};
}