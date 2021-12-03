cmake_minimum_required(VERSION 3.20)
project(task1)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES src/main.cpp
            src/logic/logic.cpp
            src/Dialog/Dialog.cpp
            Map/WayDescription/WayDescription.cpp
            Map/MapOfLocation/MapOfLocation.cpp
            Map/PriorityQueue/PriorityQueue.cpp
            Order/Order.cpp
            Truck/Truck.cpp
            Route/Route.cpp
)


include_directories(
        Map/PriorityQueue
        Map/Graph
        Map/WayDescription
        Map/MapOfLocation
        Order
        Truck
        Route
        src/Dialog
        src/logic
        LabTools
)

add_subdirectory(LabTools/lib)
add_subdirectory(Map/PriorityQueue)
add_subdirectory(Map/Graph/test)
add_subdirectory(Map/Graph/lib)
add_subdirectory(Map/MapOfLocation)

add_executable(${PROJECT_NAME} ${SOURCES})

set(LIB
        ${PROJECT_SOURCE_DIR}/lib/libGraph.a
        ${PROJECT_SOURCE_DIR}/lib/libLabTools.a)

target_link_libraries(${PROJECT_NAME} ${LIB})
