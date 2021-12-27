set(SOURCES
        main.cpp
        arr/arraysequence.h
        arr/dynamicarray.h
        list/linkedlist.h
        list/listsequence.h
        seq/sequence.h
        queue/queue.h
        tree/TreeNodeVector.h
        tree/AVL.h
        tree/sparse_matrix_BTree.h
        matrix/matrix.h
        graph/graph.h
        stack/stack.h)

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

add_executable(${CMAKE_PROJECT_NAME}_run ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}_run ${OpenCV_LIBS} Qt5::Widgets ${REQUIRED_LIBS_QUALIFIED} sfml-graphics ${Boost_LIBRARIES})