//
// Created by oleg on 17.11.2021.
//

#ifndef TASK1_ORDER_H
#define TASK1_ORDER_H

#include <iostream>


class Order {
private:
    unsigned int id;
    unsigned int number;
public:
    Order(): id(0), number(0) {}
    explicit Order(unsigned int _id, unsigned int _number = 0): id(_id), number(_number) {}

    unsigned int getId() const { return id; }
    unsigned int getNumber() const { return number; }

    void setId(unsigned int _id) { id = _id; }
    void setNumber(unsigned int _number) { number = _number; }

    void add(unsigned int _number) { number += _number; }
    void reduce(unsigned int _number) { if (number < _number) throw std::invalid_argument("vertex don't exist or indexing error"); number -= _number; }

    Order& operator ++() { ++number; return *this; }
    const Order operator ++(int) { Order temp(*this); ++id; return temp; }

    friend std::istream& operator >> (std::istream&, Order &);
    friend std::ostream& operator << (std::ostream&, const Order &);

};


#endif //TASK1_ORDER_H
