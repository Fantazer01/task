//
// Created by oleg on 15.11.2021.
//


#include "logic.h"
/*
void printWay(WayDescription &way) {
    for (auto a : way)
        std::cout << a.getName() << " ";
    std::cout << std::endl;
}
*/
WayDescription findTheNearestPoint
            (const MapOfLocation &Map, const int &from, std::list<Order> &orders, std::list<Order>::iterator &mpl) {
    WayDescription way, wayMin;
    std::list<Order>::iterator pl;

    for (pl = orders.begin(), mpl = orders.begin(); pl != orders.end(); ++pl) {
        way = Map.FindShortestWay(Graph::Vertex(from), Graph::Vertex(pl->getId()));
        if (pl == orders.begin())
            wayMin = way;
        if (wayMin.dist > way.dist) {
            wayMin = way;
            mpl = pl;
        }
    }

    return wayMin;
}

WayDescription findTheFarthestPoint
            (const MapOfLocation &Map, const int &id_WH, std::list<Order> &orders, std::list<Order>::iterator &mpl) {
    WayDescription way, wayMax;
    std::list<Order>::iterator pl;

    for (pl = orders.begin(), mpl = orders.begin(); pl != orders.end(); ++pl) {
        way = Map.FindShortestWay(Graph::Vertex(id_WH), Graph::Vertex(pl->getId()));
        if (wayMax.dist < way.dist) {
            wayMax = way;
            mpl = pl;
        }
    }

    return wayMax;
}

Truck optimizedSelectTruck(std::list<Truck> &unoccupiedTrucks) {
    Truck truck = unoccupiedTrucks.front();
    unoccupiedTrucks.pop_front();
    return truck;
}

void printRoute(const Route &r) {
    std::cout << "\n\ninfo start\n\n";
    std::cout << "id: " << r.getId() << ", id of truck: " << r.getIdTruck() << " \nways:\n";
    std::list<std::pair<WayDescription, Order>> b = r.getWays();
    for (auto c : b) {
        std::cout << c.first << " with order(point, number): " << c.second << std::endl;
    }
    std::cout << "\n\ninfo finish\n\n";
}

Route calculateRoute(int counter, const MapOfLocation &Map, const int &id_WH, std::list<Order> &orders, std::list<Truck> &unoccupiedTrucks) {
    WayDescription way;
    Truck truck;
    unsigned int capacity;
    std::list<Order>::iterator mpl;

    way = findTheFarthestPoint(Map, id_WH, orders, mpl);
    truck = optimizedSelectTruck(unoccupiedTrucks);
    capacity = truck.getCapacity();

    Route route(counter, truck.getId());

    if (capacity >= mpl->getNumber()) {
        route.addWay(std::make_pair(way, *mpl));
        capacity -= mpl->getNumber();
        orders.erase(mpl);
    } else {
        route.addWay(std::make_pair(way, Order(mpl->getId(), capacity)));
        mpl->reduce(capacity);
        capacity = 0;
    }

    //printRoute(route);
    //findTheNearestPoint работает не правильно, возвращает не кратчайший путь, а путь в ту же точку...(непонятно в какую точку)
    while (capacity > 0 && !orders.empty()) {
        way = findTheNearestPoint(Map, way.to, orders, mpl);
        if (capacity >= mpl->getNumber()) {
            route.addWay(std::make_pair(way, *mpl));
            capacity -= mpl->getNumber();
            orders.erase(mpl);
        } else {
            route.addWay(std::make_pair(way, Order(mpl->getId(), capacity)));
            mpl->reduce(capacity);
            capacity = 0;
        }
    }

    printRoute(route);

    return route;
}



