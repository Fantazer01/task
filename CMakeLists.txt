cmake_minimum_required(VERSION 3.20)
project(task1)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Map/Graph.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Map/MapOfLocation.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Map/PriorityQueue.cpp)

#set(HEADERS Map/Graph.h)

include_directories(Map)

add_executable(task1 ${SOURCES})
