cmake_minimum_required(VERSION 3.15)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(bench)
add_subdirectory(lib/googletest)
add_subdirectory(bench/benchmark)

enable_testing()