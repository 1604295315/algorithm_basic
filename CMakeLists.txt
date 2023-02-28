cmake_minimum_required(VERSION 3.16.3)

project(algorithm_basic)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_executable(main main.cpp)
# add_subdirectory(the_difference_of_stones)

# ctest_build()