//
// Created by oleg on 17.11.2021.
//

#include "Order.h"

std::istream& operator >> (std::istream& input, Order &obj) {
    input >> obj.id >> obj.number;
    return input;
}

std::ostream& operator << (std::ostream& output, const Order &obj) {
    output << obj.id << " " << obj.number;
    return output;
}