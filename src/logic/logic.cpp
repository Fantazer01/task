//
// Created by oleg on 15.11.2021.
//


#include "logic.h"

void printWay(std::vector<MapOfLocation::Vertex> &way) {
    for (auto a : way)
        std::cout << a.getName() << " ";
    std::cout << std::endl;
}


