//
// Created by oleg on 21.11.2021.
//

#ifndef TASK1_WAYDESCRIPTION_H
#define TASK1_WAYDESCRIPTION_H


#include <vector>

struct WayDescription {
public:
    unsigned int from;
    unsigned int to;
    std::vector<unsigned int> way;
    unsigned int dist;

    void reverse();

};


#endif //TASK1_WAYDESCRIPTION_H
