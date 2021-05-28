cmake_minimum_required(VERSION 3.13)

project(lab3)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/googletest)
add_subdirectory(lib/benchmark)
add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(bench)

enable_testing()