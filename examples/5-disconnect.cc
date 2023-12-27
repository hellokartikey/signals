#include <hk/signals.h>

#include <format>
#include <iostream>

auto slot1(int i) {
  std::cout << std::format("Slot function 1: value squared = {}\n", i * i);
}

auto slot2(int i) {
  std::cout << std::format("Slot function 2: value = {}\n", i);
}

auto slot3(int i) {
  std::cout << std::format("Slot function 3: 10 * value = {}\n", 10 * i);
}

auto main() -> int {
  auto signal = hk::signals::Signal<int>{};

  auto conn1 = hk::signals::connect(signal, slot1);
  auto conn2 = hk::signals::connect(signal, slot2);

  std::cout << "--- Before ---\n";
  signal(9);

  std::cout << std::format("Connections: {}\n", signal.connections());
  std::cout << "--- Disconnecting ---\n";
  hk::signals::disconnect(signal, conn2);
  std::cout << std::format("Connections: {}\n", signal.connections());

  auto conn3 = hk::signals::connect(signal, slot3);

  std::cout << "--- After ---\n";
  signal(11);
  std::cout << std::format("Connections: {}\n", signal.connections());

  std::cout << std::format("conn1={}\nconn2={}\nconn3={}\n", conn1, conn2,
                           conn3);

  return 0;
}