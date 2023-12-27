cmake_minimum_required(VERSION 3.25)

project(
  signals
  VERSION 0.1.0
  DESCRIPTION "A simple header-only C++ library for signals & slots mechanism."
  HOMEPAGE_URL "https://github.com/hellokartikey/signals"
  LANGUAGES CXX)

option(BUILD_EXAMPLES "Build examples" OFF)

set(HK_LIB signals)
set(HK_NAMESPACE hk)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/clang-format.cmake)

add_subdirectory(include)

if(BUILD_EXAMPLES)
  add_subdirectory(examples)
endif(BUILD_EXAMPLES)
