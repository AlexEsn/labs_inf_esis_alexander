cmake_minimum_required(VERSION 3.0)

project(lab1.1 VERSION 1.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)

add_executable(lab1 main.c
        ${CMAKE_SOURCE_DIR}/Array_lib/array.c ${CMAKE_SOURCE_DIR}/Array_lib/array.h
        ${CMAKE_SOURCE_DIR}/CException_lib/CException.c ${CMAKE_SOURCE_DIR}/CException_lib/CException.h
        examples.c examples.h)