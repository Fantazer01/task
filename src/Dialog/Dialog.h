//
// Created by oleg on 17.11.2021.
//

#ifndef TASK1_DIALOG_H
#define TASK1_DIALOG_H

#include "MapOfLocation.h"
#include "Order.h"
#include "logic.h"
#include "LabTools.h"
#include <list>
#include <fstream>

int dialog();

MapOfLocation initMap(char *filename);
void setMap(MapOfLocation &map);

void addOrder(std::list<Order> &);
void printOrders(const std::list<Order> &);

void calculateRoute(const MapOfLocation &, const std::list<Order> &, const int &);

#endif //TASK1_DIALOG_H
