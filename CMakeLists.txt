cmake_minimum_required(VERSION 3.25)

project(
  signals
  VERSION 0.1.0
  DESCRIPTION "A simple header-only C++ 20 library for signals and slots mechanism."
  HOMEPAGE_URL "https://github.com/hellokartikey/signals"
  LANGUAGES CXX)

set(HK_LIB ${PROJECT_NAME})
set(HK_NAMESPACE hk)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(include)
add_subdirectory(examples)
