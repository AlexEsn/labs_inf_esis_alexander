set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCE
    main.cpp
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
set(QT_LIB ${REQUIRED_LIBS_QUALIFIED})

#############################################################################

add_executable(${PROJECT_NAME}_tst ${SOURCE})

add_test(NAME ${BINARY}_tst COMMAND ${BINARY}_tst)

target_link_libraries(${BINARY}_tst ${QT_LIB} ${CMAKE_PROJECT_NAME}_lib gtest)