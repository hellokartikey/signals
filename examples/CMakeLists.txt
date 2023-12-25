function(hk_example EXAMPLE_NAME)
  add_executable(${EXAMPLE_NAME} ${EXAMPLE_NAME}.cc)

  target_include_directories(
    ${EXAMPLE_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include)
endfunction()

hk_example(1-simple)
hk_example(2-class)
hk_example(3-args)
hk_example(4-overloads)
