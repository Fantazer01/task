//
// Created by oleg on 17.11.2021.
//

#ifndef TASK1_ORDER_H
#define TASK1_ORDER_H


class Order {
private:
    unsigned int id;
    int number;
public:
    Order(): id(0), number(0) {}
    explicit Order(unsigned int _id, int _number = 0): id(_id), number(_number) {}

    unsigned int getId() const { return id; }
    int getNumber() const { return number; }

    void setId(unsigned int _id) { id = _id; }
    void setNumber(int _number) { number = _number; }

    Order& operator ++() { ++number; return *this; }
    const Order operator ++(int) { Order temp(*this); ++id; return temp; }

};


#endif //TASK1_ORDER_H
