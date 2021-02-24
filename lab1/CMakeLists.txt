cmake_minimum_required(VERSION 3.17)
project(lab1 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab1 main.c
        CException.c CException.h
        array.c array.h
        integer.c integer.h
        reals.c reals.h)