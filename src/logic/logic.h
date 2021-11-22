//
// Created by oleg on 15.11.2021.
//

#ifndef TASK1_LOGIC_H
#define TASK1_LOGIC_H

#include "Dialog.h"

void printWay(std::vector<MapOfLocation::Vertex> &way);
Route calculateRoute(int counter, const MapOfLocation &Map, const int &id_WH, std::list<Order> &orders, std::list<Truck> &trucks);



#endif //TASK1_LOGIC_H
