//
// Created by oleg on 17.11.2021.
//

#ifndef TASK1_DIALOG_H
#define TASK1_DIALOG_H

#include "MapOfLocation.h"
#include "Order.h"
#include "Truck.h"
#include "Route.h"

#include "logic.h"
#include "LabTools.h"
#include <list>
#include <fstream>

int dialog();

MapOfLocation initMap(const int &argc, char* argv[]);
void setMap(MapOfLocation &map);
void putGraph(MapOfLocation &map);

void addOrder(std::list<Order> &);
void printOrders(const std::list<Order> &);

void calculatePrintRoutes(const MapOfLocation &, const int &, std::list<Order>, const std::vector<Truck> &);

#endif //TASK1_DIALOG_H
