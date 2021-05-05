cmake_minimum_required(VERSION 3.5)

project(lab2 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

#all library file
add_executable(
        lab2 main.cpp
        ${CMAKE_SOURCE_DIR}/arr/arraysequence.cpp ${CMAKE_SOURCE_DIR}/arr/arraysequence.h
        ${CMAKE_SOURCE_DIR}/arr/dynamicarray.cpp ${CMAKE_SOURCE_DIR}/arr/dynamicarray.h
        ${CMAKE_SOURCE_DIR}/list/linkedlist.cpp ${CMAKE_SOURCE_DIR}/list/linkedlist.h
        ${CMAKE_SOURCE_DIR}/list/listsequence.cpp ${CMAKE_SOURCE_DIR}/list/listsequence.h
        ${CMAKE_SOURCE_DIR}/sequence/custom.cpp ${CMAKE_SOURCE_DIR}/sequence/custom.h
        ${CMAKE_SOURCE_DIR}/sequence/sequence.cpp  ${CMAKE_SOURCE_DIR}/sequence/sequence.h
)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

#all qt file
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(1
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(1 SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(1
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(1 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)