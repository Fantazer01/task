//
// Created by oleg on 07.11.2021.
//

#ifndef TASK1_MAPOFLOCATION_H
#define TASK1_MAPOFLOCATION_H

#include "Graph.h"
#include "WayDescription.h"
#include "PriorityQueue.h"
#include <exception>

class MapOfLocation: public Graph {
private:
    //таблица кратчайших путей
    std::vector<WayDescription> tableOfShortestWay;
    //helper methods
    void initializationParameters(std::pair<int, int> *setOfVertexes, int *pred, int *distance);
    std::vector<WayDescription> findShortWays(const int &index_vertex);
    WayDescription ShortestWayFromTo(int &from, int &to) const;
public:
    MapOfLocation() = default;
    MapOfLocation(const std::vector<Vertex> &_vertexes, const std::vector<Edge> &_signature);
    explicit MapOfLocation(const Graph &graph);

    WayDescription FindShortestWay(const Vertex &ver1, const Vertex &ver2) const;

    void answerOnYourQuestion() const;


};


#endif //TASK1_MAPOFLOCATION_H
