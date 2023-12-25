#include <iostream>
#include <format>

#include <hk/signals/signals.h>


auto overloaded(int i) {
  std::cout << std::format("This is overloaded(int): {}\n", i);
}

auto overloaded(float i) {
  std::cout << std::format("This is overloaded(float): {}\n", i);
}

auto main() -> int {
  auto signal = hk::Signal<int>{};

  signal.connect(overloaded);

  signal(9);
  
  return 0;
}
