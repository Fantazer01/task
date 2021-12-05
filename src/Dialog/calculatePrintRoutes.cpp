//
// Created by oleg on 06.12.2021.
//

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include "Dialog.h"

void calculatePrintRoutes
        (const MapOfLocation &Map, const int &id_WH, std::list<Order> orders, const std::vector<Truck> &trucks)
{
    std::list<Route> routes;
    std::list<std::pair<Truck, int>> TrucksAndBusy;
    int counterId = 0;
    uint timer = 0;

    for (const Truck &a : trucks)
        TrucksAndBusy.emplace_back(a, 0);

    //std::cout << "\ninfo\n\n";
    while (!orders.empty() && TrucksAndBusy.begin() != TrucksAndBusy.end() && timer >= (*TrucksAndBusy.begin()).second)
    {
        routes.push_back(calculateRoute(counterId, Map, id_WH, orders, TrucksAndBusy, timer));
        ++counterId;
        ++timer;
    }

    /*
    for (Route a : routes) {
        std::cout << "id: " << a.getId() << ", id of truck: " << a.getIdTruck() << " \nways:\n";
        std::list<std::pair<WayDescription, Order>> b = a.getWays();
        for (auto c : b) {
            std::cout << c.first;
        }
        std::cout << "\nnew\n";
    }
     */
    //std::cout << "\n\ninfo\n\n";

}

