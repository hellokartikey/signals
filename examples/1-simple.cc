#include <iostream>

#include <hk/signals/signals.h>

auto slot1(int i) {
  std::cout
    << "Slot 1: value = "
    << i
    << "\n";
}

auto slot2(int i) {
  std::cout
    << "Slot 2: value squared = "
    << i * i
    << "\n";
}

auto main() -> int {
  auto signal = hk::Signal<int>{};

  signal.connect(slot1);
  signal.connect(slot2);

  signal.emit(9);

  return 0;
}
