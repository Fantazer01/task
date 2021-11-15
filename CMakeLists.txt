cmake_minimum_required(VERSION 3.20)
project(task1)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
        Map/Graph/Graph.cpp
        Map/MapOfLocation/MapOfLocation.cpp
        Map/PriorityQueue/PriorityQueue.cpp
        src/logic.cpp)

include_directories(Map/PriorityQueue)

add_subdirectory(Map/PriorityQueue)

#set(HEADERS Map/Graph.h)

include_directories(
        Map/PriorityQueue
        Map/Graph
        Map/MapOfLocation
)

add_executable(task1 ${SOURCES})

#target_link_libraries(main /usr/lib)
