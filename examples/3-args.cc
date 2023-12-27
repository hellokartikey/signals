#include <hk/signals.h>

#include <format>
#include <iostream>

auto slot_func(int i, std::string_view msg) {
  std::cout << std::format("{}: {}\n", msg, i);
}

auto main() -> int {
  auto signal = hk::signals::Signal<int, std::string_view>{};

  // signal.connect(slot_func);
  hk::signals::connect(signal, &slot_func);

  signal(9, "This is a message");

  return 0;
}
