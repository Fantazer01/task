cmake_minimum_required(VERSION 3.20)
project(testMapOfLocation)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        testMapOfLocation.cpp
        ../../Graph/Graph.cpp
        ../../WayDescription/WayDescription.cpp
        ../../PriorityQueue/PriorityQueue.cpp
        ../MapOfLocation.cpp)


add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} gtest gtest_main pthread)
