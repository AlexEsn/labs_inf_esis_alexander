set(SOURCES
        main.cpp
        arr/arraysequence.h
        arr/dynamicarray.h
        list/linkedlist.h
        list/listsequence.h
        vector/vector.h
        seq/sequence.h
        queue/queue.h
        )

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(${CMAKE_PROJECT_NAME}_run ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}_run sfml-graphics)