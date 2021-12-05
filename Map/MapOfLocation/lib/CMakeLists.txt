cmake_minimum_required(VERSION 3.20)
project(MapOfLocation)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE
        ../../Graph/Graph.cpp
        ../../WayDescription/WayDescription.cpp
        ../MapOfLocation.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCE})