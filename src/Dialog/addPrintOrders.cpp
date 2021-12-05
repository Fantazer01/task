//
// Created by oleg on 05.12.2021.
//

#include <iostream>
#include "Dialog.h"

void addOrder(std::list<Order> &orders) {
    int id, num;

    std::cout << "Enter order data (id point and number of one): ";
    getNum(id);
    getNum(num);

    Order order(id, num);

    std::list<Order>::iterator p;

    for (p = orders.begin(); p != orders.end(); ++p)
        if (order.getId() == p->getId()) {
            p->add(order.getNumber());
            return;
        }

    orders.push_back(order);
}

void printOrders(const std::list<Order> &orders) {
    std::cout << "List of orders (id point and number of one):\n";

    if (orders.size() == 0) {
        std::cout << "Empty" << std::endl;
        return;
    }

    for (const Order &a : orders)
        std::cout << a << std::endl;
}
