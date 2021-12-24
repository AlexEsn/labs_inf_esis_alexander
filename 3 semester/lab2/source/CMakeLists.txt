set(SOURCES
        main.cpp
        arr/arraysequence.h
        arr/dynamicarray.h
        list/linkedlist.h
        list/listsequence.h
        seq/sequence.h
        queue/queue.h
        sort/sort.h
        sort/ISorter.h
        tree/tree.h)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    message(" ")
    message("CMAKE IN DEBUG MODE")
    message(" ")
    add_compile_options(-Wall)
    add_definitions(-DDEBUG)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    message(" ")
    message("CMAKE IN RELEASE MODE")
    message(" ")
endif ()

find_package(OpenCV REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIR})

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME} ${OpenCV_LIBS} Qt5::Widgets X11 ${REQUIRED_LIBS_QUALIFIED} sfml-graphics ${Boost_LIBRARIES})