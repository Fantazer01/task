//
// Created by oleg on 21.11.2021.
//

#include "Route.h"

uint Route::getDistance() const
{
    uint distance = 0;
    std::list<std::pair<WayDescription, Order>>::const_iterator it;
    for (it = ways.begin(); it != ways.end(); ++it)
        distance += it->first.dist;

    return distance;
}