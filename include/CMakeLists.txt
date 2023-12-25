add_library(${HK_LIB} INTERFACE)

add_library(
  ${HK_NAMESPACE}::${HK_LIB} ALIAS ${HK_LIB})

target_include_directories(
  ${HK_LIB}
  INTERFACE
  $<BUILD_INTERFACE:${${HK_LIB}_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

include(GNUInstallDirs)
install(
  TARGETS ${HK_LIB}
  EXPORT ${HK_LIB}_Targets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${PROJECT_BINARY_DIR}/${HK_LIB}ConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion)

configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/${HK_LIB}Config.cmake.in"
  "${PROJECT_BINARY_DIR}/${HK_LIB}Config.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${HK_LIB}/cmake)

install(
  EXPORT ${HK_LIB}_Targets
  FILE ${HK_LIB}Targets.cmake
  NAMESPACE ${HK_NAMESPACE}::
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${HK_LIB}/cmake)

install(
  FILES
  "${PROJECT_BINARY_DIR}/${HK_LIB}Config.cmake"
  "${PROJECT_BINARY_DIR}/${HK_LIB}ConfigVersion.cmake"
  DESTINATION
  "${CMAKE_INSTALL_DATAROOTDIR}/${HK_LIB}/cmake")

include(CMakePrintHelpers)
cmake_print_variables(PROJECT_SOURCE_DIR)
cmake_print_variables(PROJECT_BINARY_DIR)
cmake_print_variables(CMAKE_INSTALL_INCLUDEDIR)
cmake_print_variables(CMAKE_INSTALL_DATAROOTDIR)
cmake_print_variables(CMAKE_INSTALL_LIBDIR)
cmake_print_variables(CMAKE_INSTALL_BINDIR)
cmake_print_variables(${HK_LIB}_SOURCE_DIR)
cmake_print_variables(HK_NAMESPACE)

install(
  DIRECTORY ${PROJECT_SOURCE_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/)
