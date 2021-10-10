enable_testing()

set(SOURCES main.cpp)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(${CMAKE_PROJECT_NAME}_tst ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}_tst gtest gtest_main)

add_test(NAME ${CMAKE_PROJECT_NAME}_tst COMMAND ${CMAKE_PROJECT_NAME}_tst)