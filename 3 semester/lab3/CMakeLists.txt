cmake_minimum_required(VERSION 3.21)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(source)
add_subdirectory(tests)
add_subdirectory(bench)
add_subdirectory(library/googletest)
add_subdirectory(library/benchmark)

enable_testing()