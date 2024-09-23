include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(
    advent_of_code_tests
    day7_test.cpp    
)

target_link_libraries(
  advent_of_code_tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(advent_of_code_tests)
