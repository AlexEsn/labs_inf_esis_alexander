set(SOURCES
        main.cpp
        arr/arraysequence.h
        arr/dynamicarray.h
        list/linkedlist.h
        list/listsequence.h
        vector/vector.h
        seq/sequence.h
        matrix/matrix.h
        matrix/squareMatrix.h
        matrix/triangularMatrix.h
        matrix/diagonalMatrix.h
#        graph/graph.h graph/graph.cpp
        queue/queue.h
        )

#############################################################################
#SFML
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

#############################################################################

add_executable(${CMAKE_PROJECT_NAME}_run ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}_run ${REQUIRED_LIBS_QUALIFIED} sfml-graphics)