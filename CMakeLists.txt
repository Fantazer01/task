cmake_minimum_required(VERSION 3.20)
project(task1)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES src/main.cpp
            src/logic/logic.cpp
            src/Dialog/Dialog.cpp
            LabTools/LabTools.cpp
            Map/Graph/Graph.cpp
            Map/MapOfLocation/MapOfLocation.cpp
            Map/PriorityQueue/PriorityQueue.cpp
            Order/Order.cpp)

include_directories(Map/PriorityQueue)

add_subdirectory(Map/PriorityQueue)

#set(HEADERS Map/Graph.h)

include_directories(
        Map/PriorityQueue
        Map/Graph
        Map/MapOfLocation
        Order
        src/Dialog
        LabTools)

add_executable(task1 ${SOURCES})

#target_link_libraries(main /usr/lib)
