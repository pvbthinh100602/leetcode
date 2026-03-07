set(PROBLEM_ID "problem_1888")

add_executable(${PROBLEM_ID}
    solution.cpp
    test.cpp
)

target_include_directories(problem_1888 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROBLEM_ID}
    gtest
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROBLEM_ID})