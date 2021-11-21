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

std::ostream& operator << (std::ostream& output, const WayDescription &way) {
        output << "from: " << way.from << " to: " << way.to << " way: ";
        for (unsigned int point : way.way)
            output << point << " ";
        output << "dist: " << way.dist;
        output << std::endl;

        return output;
}
