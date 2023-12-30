#include <hk/tunnel.h>

#include <format>
#include <iostream>

auto slot_fun(float i) -> int {
  std::cout << std::format("Slot function called: {}\n", i);

  return int(i) * 10;
}

auto main() -> int {
  auto tunnel = hk::signals::Tunnel<int, float>{};

  tunnel.connect(slot_fun);

  std::cout << std::format("is_connected() = {}\n", tunnel.is_connected());

  std::cout << std::format("emit() = {}\n", tunnel(3.1415));

  return 0;
}