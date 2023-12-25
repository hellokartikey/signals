#include <iostream>
#include <format>

#include <hk/signals/signals.h>

auto slot_fun(int i) {
  std::cout
    << std::format("Slot function: value squared = {}\n", i * i);
}

auto main() -> int {
  auto signal = hk::Signal<int>{};

  signal.connect(
    [] (int value) { std::cout << std::format("Lambda: {}\n", value); });

  signal.connect(slot_fun);

  signal.emit(9);

  return 0;
}