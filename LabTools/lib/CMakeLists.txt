cmake_minimum_required(VERSION 3.20)
project(LabTools)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE
        ../LabTools.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCE})