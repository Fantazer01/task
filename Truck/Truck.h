//
// Created by oleg on 21.11.2021.
//

#ifndef TASK1_TRUCK_H
#define TASK1_TRUCK_H


class Truck {
private:
    unsigned int id;
    unsigned int capacity;
    unsigned int speed;
public:
    Truck(): id(0), capacity(0), speed(0) {}
    Truck(unsigned int _id, unsigned int _capacity, unsigned int _speed): id(_id), capacity(_capacity), speed(_speed) {}

    unsigned int getId() const { return id; }
    unsigned int getCapacity() const { return capacity; }
    unsigned int getSpeed() const { return speed; }

    void setId(unsigned int _id) { id = _id; }
    void setCapacity(unsigned int _capacity) { capacity = _capacity; }
    void setSpeed(unsigned int _speed) { speed = _speed; }
};


#endif //TASK1_TRUCK_H
