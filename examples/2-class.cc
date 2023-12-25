#include <functional>
#include <iostream>
#include <format>

#include <hk/signals/signals.h>

class Input {
public:
  hk::Signal<int> signal;

private:
  int _value = 0;

public:
  auto value(int i) -> void {
    _value = i;
  }

  auto press() -> void {
    signal(_value);
  }
};

class Label {
private:
  std::string text = "Input Received!!!";
  int value = 10;

public:
  Label(std::string_view str) { text = str; }

  auto display(int i) -> void {
    value = i;
    std::cout << std::format("({}) {}\n", value, text);
  }
};

auto main() -> int {
  auto i = Input{};
  auto l1 = Label{"This is label 1"};
  auto l2 = Label{"This is label 2"};

  i.signal.connect( &Label::display, l1 );
  i.signal.connect( &Label::display, l2 );

  i.value(9);

  i.press();
}
