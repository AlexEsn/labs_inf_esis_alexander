set(SOURCES main.cpp)

add_executable(${CMAKE_PROJECT_NAME}_bench ${SOURCES})

include_directories(../src)

target_link_libraries(${CMAKE_PROJECT_NAME}_bench benchmark::benchmark)