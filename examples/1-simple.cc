#include <iostream>
#include <format>

#include <hk/signals/signals.h>

auto slot_fun(int i) {
  std::cout
    << std::format("Slot function: value squared = {}\n", i * i);
}

auto main() -> int {
  auto signal = hk::signals::Signal<int>{};

  hk::signals::connect(
    signal,
    [] (int value) { std::cout << std::format("Lambda: {}\n", value); });

  hk::signals::connect(signal, slot_fun);

  signal.emit(9);

  return 0;
}