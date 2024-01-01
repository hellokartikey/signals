cmake_minimum_required(VERSION 3.25)

project(
  signals
  VERSION 0.1.0
  DESCRIPTION "A simple header-only C++ library for signals & slots mechanism."
  HOMEPAGE_URL "https://github.com/hellokartikey/signals"
  LANGUAGES CXX)

option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build unit tests" OFF)
option(CLANG_FORMAT "Use clang-format" OFF)

set(HK_LIB hk)
set(HK_SIGNALS signals)
set(HK_NAMESPACE hk)
set(HK_INCLUDE hk)
set(HK_HEADERS hk/signal.h hk/tunnel.h)
set(HK_SOURCE)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CLANG_FORMAT)
  include(cmake/clang-format.cmake)
endif(CLANG_FORMAT)

add_subdirectory(include)

if(BUILD_EXAMPLES)
  add_subdirectory(examples)
endif(BUILD_EXAMPLES)
