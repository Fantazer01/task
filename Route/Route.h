//
// Created by oleg on 21.11.2021.
//

#ifndef TASK1_ROUTE_H
#define TASK1_ROUTE_H

#include "MapOfLocation.h"
#include "Order.h"
#include "Truck.h"

#include <list>

class Route {
private:
    unsigned int id;
    unsigned int idTruck;
    std::list<std::pair<WayDescription, Order>> ways;
public:
    Route(): id(0), idTruck(0) {}
    Route(unsigned int _id, unsigned int _idTruck): id(_id), idTruck(_idTruck) {}

    unsigned int getId() const { return id; }
    unsigned int getIdTruck() const { return idTruck; }
    std::list<std::pair<WayDescription, Order>> getWays() const { return ways; }

    void setId(unsigned int _id) { id = _id; }
    void setIdTruck(unsigned int _idTruck) { idTruck = _idTruck; }

    void addWay(const std::pair<WayDescription, Order> &_way) { ways.push_back(_way); }
};


#endif //TASK1_ROUTE_H
