find_package(signals)

function(hk_example EXAMPLE_NAME)
  add_executable(${EXAMPLE_NAME} ${EXAMPLE_NAME}.cc)
  target_link_libraries(${EXAMPLE_NAME} hk::signals)
endfunction()

hk_example(1-simple)
hk_example(2-class)
hk_example(3-args)
hk_example(4-overloads)
hk_example(5-disconnect)
hk_example(6-tunnel)
hk_example(7-exception)
