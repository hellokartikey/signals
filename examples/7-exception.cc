#include <hk/tunnel.h>

#include <format>
#include <iostream>

auto main() -> int {
  auto tunnel = hk::signals::Tunnel<int, float>{};

  std::cout << std::format("is_connected() = {}\n", tunnel.is_connected());

  try {
    tunnel(3.1415);
  } catch (const std::runtime_error& e) {
    std::cout << "Exception thrown -\n"
              << "\t" << e.what() << "\n";
  }

  return 0;
}