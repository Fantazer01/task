cmake_minimum_required(VERSION 3.20)
project(testPriorityQueue)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES testingPriorityQueue.cpp
            PriorityQueue.cpp)


add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} gtest gtest_main pthread)
