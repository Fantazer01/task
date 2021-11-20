//
// Created by oleg on 21.11.2021.
//

#include "WayDescription.h"

void WayDescription::reverse() {
    int size = way.size();
    std::swap(from, to);

    for (int i = 0; i < size/2; ++i)
        std::swap(way[i], way[size - i - 1]);
}
