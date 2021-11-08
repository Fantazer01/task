//
// Created by oleg on 07.11.2021.
//

#ifndef TASK1_MAPOFLOCATION_H
#define TASK1_MAPOFLOCATION_H

#include "Graph.h"
#include "PriorityQueue.h"
#include <exception>

class MapOfLocation: public Graph {
public:
    struct WayDescription {
        int from;
        int to;
        std::vector<int> way;
    };
private:
    //таблица кратчайших путей
    std::vector<WayDescription> tableOfShortestWay;
    //helper methods
    void initializationParameters(std::pair<int, int> *setOfVertexes, int *color, int *pred);
    std::vector<WayDescription> findShortWays(const int &index_vertex);
    WayDescription ShortestWayFromTo(int &from, int &to);
public:
    MapOfLocation() = default;
    MapOfLocation(const std::vector<Vertex> &_vertexes, const std::vector<Edge> &_signature);

    std::vector<Vertex> FindShortestWay(const Vertex &ver1, const Vertex &ver2);

};


#endif //TASK1_MAPOFLOCATION_H
