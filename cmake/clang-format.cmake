file(GLOB_RECURSE ALL_SOURCE_FILES ${HK_HEADERS} ${HK_SRC})

add_custom_target(
    clangformat
    ALL
    COMMAND /usr/bin/clang-format
    -i
    ${ALL_SOURCE_FILES}
)
