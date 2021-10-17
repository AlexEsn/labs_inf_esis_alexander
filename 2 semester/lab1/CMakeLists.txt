cmake_minimum_required(VERSION 3.15)
project(lab1)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(bench)
add_subdirectory(lib/googletest)
add_subdirectory(lib/benchmark)

enable_testing()