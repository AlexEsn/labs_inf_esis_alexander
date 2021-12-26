cmake_minimum_required(VERSION 3.15)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(source)
add_subdirectory(tst)
add_subdirectory(bench)
add_subdirectory(library/googletest)
add_subdirectory(library/benchmark)

enable_testing()