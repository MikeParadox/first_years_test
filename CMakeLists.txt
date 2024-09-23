cmake_minimum_required(VERSION 3.5)

project(advent_of_code
        VERSION 1.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE "DEBUG")
endif()

enable_testing()

add_subdirectory(src)
add_subdirectory(test)


target_compile_options(${PROJECT_NAME} PUBLIC -g -ggdb -Werror -Wall -Wpedantic)
# -ftime-report)

