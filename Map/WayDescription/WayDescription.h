//
// Created by oleg on 21.11.2021.
//

#ifndef TASK1_WAYDESCRIPTION_H
#define TASK1_WAYDESCRIPTION_H


#include <vector>
#include <iostream>

struct WayDescription {
public:
    unsigned int from;
    unsigned int to;
    std::vector<unsigned int> way;
    unsigned int dist;

    WayDescription(): from(0), to(0), dist(0) {}
    WayDescription(unsigned int _from, unsigned int _to): from(_from), to(_to), dist(0) {}

    void reverse();

    friend std::ostream& operator << (std::ostream&, const WayDescription &);
};


#endif //TASK1_WAYDESCRIPTION_H
