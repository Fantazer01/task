cmake_minimum_required(VERSION 3.20)
project(Graph)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE
        ../Graph.cpp)

add_library(${PROJECT_NAME} STATIC ../Graph.cpp)
