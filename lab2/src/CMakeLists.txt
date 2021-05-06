set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCE
    main.cpp
    arr/arraysequence.cpp arr/arraysequence.h
    arr/dynamicarray.cpp arr/dynamicarray.h
    list/linkedlist.cpp list/linkedlist.h
    list/listsequence.cpp list/listsequence.h
    sequence/custom.cpp sequence/custom.h
    sequence/sequence.cpp  sequence/sequence.h
)

################################################################################
#all qt settings

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets)

list(APPEND CMAKE_PREFIX_PATH "/home/alexesn/Qt/6.0.2/gcc_64")

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

#############################################################################

add_executable(${PROJECT_NAME}_run ${SOURCE})

target_link_libraries(${PROJECT_NAME}_run ${REQUIRED_LIBS_QUALIFIED})

add_library(${BINARY}_lib STATIC ${SOURCES})