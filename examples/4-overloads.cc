#include <iostream>
#include <format>

#include <hk/signals.h>


auto overloaded(int i) -> void {
  std::cout << std::format("This is overloaded(int): {}\n", i);
}

auto overloaded(float i) -> void {
  std::cout << std::format("This is overloaded(float): {}\n", i);
}

auto main() -> int {
  auto signal = hk::signals::Signal<int>{};
    
  hk::signals::connect(signal, [] (int i) { overloaded(i); });

  signal(9);
  
  return 0;
}
