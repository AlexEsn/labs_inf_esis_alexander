set(SOURCES
        main.cpp
        tst_arr/test_dynamicarray.cpp
        tst_arr/test_arraysequence.cpp
        tst_list/test_linkedlist.cpp
        tst_list/test_listsequence.cpp
        tst_sort/test_sort.cpp)

#############################################################################
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(${CMAKE_PROJECT_NAME}_tst ${SOURCES})

include_directories(../src)

target_link_libraries(${CMAKE_PROJECT_NAME}_tst ${QT_LIB} gtest gtest_main)

add_test(NAME ${CMAKE_PROJECT_NAME}_tst COMMAND ${CMAKE_PROJECT_NAME}_tst)