# signals
`hk::signals` is a header only signals and slots library for C++.
It allows you have some communication between classes with ease.
It was inspired by [Qt's Signals and Slots](https://doc.qt.io/qt-6/signalsandslots.html) mechanism. Unlike Qt's implementation my implementation doesn't require MOC and works natively in C++ and has no dependencies.

### A very basic example
```C++
#include <iostream>
#include <format>

#include <hk/signals/signals.h>

auto slot_fun(int i) {
  std::cout
    << std::format("Slot function: value squared = {}\n", i * i);
}

auto main() -> int {
  /** Create a Signal object to manage everything */
  auto signal = hk::signals::Signal<int>{};

  /** Connect your lambdas using signals::connect() */
  hk::signals::connect(
    signal,
    [] (int value) { std::cout << std::format("Lambda: {}\n", value); });

  /** Or connect regular functions via member function Signal::connect() */
  signal.connect(slot_fun);

  /** Connected functions will be called whenever signal is emitted  */
  signal.emit(9);

  return 0;
}
```

### Output
```
Lambda: 9
Slot function: value squared = 81
```

## Usage via CMake
```CMake
project(hk_signals_example)

include(FetchContent)
FetchContent_Declare(
  hk_signals 
  GIT_REPOSITORY https://github.com/hellokartikey/signals.git)
FetchContent_MakeAvailable(hk_signals)

add_executable(
  ${PROJECT_NAME}
  main.cc)

target_link_libraries(
  ${PROJECT_NAME}
  hk::signals)
```
