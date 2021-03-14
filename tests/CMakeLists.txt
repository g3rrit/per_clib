
enable_testing()
message(STATUS "Testing enabled")

function(add_unittest file)

    get_filename_component(file_we ${file} NAME_WE)

    message(STATUS "Adding test: ${file_we}")

    add_executable(${file_we} "${PROJECT_SOURCE_DIR}/tests/unittests/${file}")
    target_include_directories(${file_we} PUBLIC
        "${PROJECT_SOURCE_DIR}/tests"
        "${PROJECT_SOURCE_DIR}/include"
        "${PROJECT_SOURCE_DIR}/external/snow"
    )

    add_dependencies(${file_we} per_clib)
    target_link_libraries(${file_we} PRIVATE per_clib)

    add_test(NAME ${file_we} COMMAND ${file_we})
endfunction()

add_unittest("test_per_libc_functions.c")


# Add custom target to print output of individual tests
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --verbose)
