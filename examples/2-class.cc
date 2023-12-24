#include <functional>
#include <iostream>

#include <hk/signals/signals.h>

class Input {
public:
  hk::Signal<> signal;

private:
  int _value = 0;

public:
  auto value(int i) -> void {
    _value = i;
  }

  auto press() -> void {
    signal();
  }
};

class Label {
private:
  std::string text = "Input Received!!!";

public:
  auto display() -> void {
    std::cout
      << text
      << "\n";
  }
};

auto main() -> int {
  auto i = Input{};
  auto l = Label{};

  i.signal.connect( &Label::display, l );

  i.value(9);
  i.press();
}
