//
// Created by oleg on 21.11.2021.
//

#ifndef TASK1_WAYDESCRIPTION_H
#define TASK1_WAYDESCRIPTION_H


#include <utility>
#include <vector>
#include <iostream>

struct WayDescription {
public:
    uint from;
    uint to;
    std::vector<uint> way;
    uint dist;

    WayDescription(): from(0), to(0), dist(0) {}
    WayDescription(uint _from, uint _to): from(_from), to(_to), dist(0) {}
    WayDescription(uint _from, uint _to, std::vector<uint> _way): from(_from), to(_to), way(std::move(_way)), dist(0) {}
    WayDescription(uint _from, uint _to, std::vector<uint> _way, uint _dist): from(_from), to(_to), way(std::move(_way)), dist(_dist) {}

    void reverse();

    bool operator == (const WayDescription &wayD) const
    { return
        (from == wayD.from && to == wayD.to && way == wayD.way && dist == wayD.dist);
    }

    friend std::ostream& operator << (std::ostream&, const WayDescription &);
};


#endif //TASK1_WAYDESCRIPTION_H
