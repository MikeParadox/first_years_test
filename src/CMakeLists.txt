add_library(Advent ../includes/day6.h day6.cpp
../includes/day5.h day5.cpp
../includes/day4.h day4.cpp
../includes/day3.h day3.cpp
../includes/day2.h day2.cpp
../includes/day1.h day1.cpp
)
add_executable(${PROJECT_NAME} main.cpp day6.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Advent)


