add_executable(1-simple 1-simple.cc)

target_include_directories(
  1-simple
  PRIVATE ${PROJECT_SOURCE_DIR}/include)

add_executable(2-class 2-class.cc)

target_include_directories(
  2-class
  PRIVATE ${PROJECT_SOURCE_DIR}/include)
