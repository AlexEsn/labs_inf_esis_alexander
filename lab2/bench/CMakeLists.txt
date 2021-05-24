set(SOURCE
        main.cpp
        )

add_executable(${CMAKE_PROJECT_NAME}_bench ${SOURCE})

find_package(benchmark REQUIRED)

target_link_libraries(${CMAKE_PROJECT_NAME}_bench ${CMAKE_PROJECT_NAME}_lib benchmark::benchmark)