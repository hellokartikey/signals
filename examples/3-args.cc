#include <iostream>
#include <format>

#include <hk/signals/signals.h>


auto slot_func(int i, std::string_view msg) {
  std::cout << std::format("{}: {}\n", msg, i);
}

auto main() -> int {
  auto signal = hk::Signal<int, std::string_view>{};

  signal.connect(slot_func);

  signal(9, "This is a message");
  
  return 0;
}
