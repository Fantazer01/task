//
// Created by oleg on 07.11.2021.
//

#include "MapOfLocation.h"
#include <list>


void MapOfLocation::initializationParameters(std::pair<int, int> *setOfVertexes, int *pred, int *distance) {
    for (int i = 0; i < getNumVer(); ++i) {
        setOfVertexes[i].first = vertexes[i].second;
        setOfVertexes[i].second = -1;
        pred[i] = -1;
        distance[i] = -1;
    }
}

std::vector<WayDescription> MapOfLocation::findShortWays(const int &index_vertex) {
    using namespace std;

    vector<WayDescription> ways(getNumVer());//вектор самых коротких путей от вершины, индекс которой передается, до каждой другой вершины
    //заготовка для алгоритма Дейкстры
    pair<int, int> setOfVertexes[getNumVer()];//first - index, second - distance
    int pred[getNumVer()];
    int distance[getNumVer()];
    pair<int, int> curVer;

    initializationParameters(setOfVertexes, pred, distance);
    PriorityQueue queue(getNumVer(), setOfVertexes);
    queue.decreaseKey(index_vertex, 0);


    while (!queue.empty()) {
        curVer = queue.extractMim();
        distance[curVer.first] = curVer.second;

        for (int i = 0; i < getNumVer(); ++i) {
            if (distBetweenVertexes(curVer.first, i) < 0)
                continue;
            if (distance[i] < 0 || distance[i] > distBetweenVertexes(curVer.first, i) + distance[curVer.first]) {
                distance[i] = distBetweenVertexes(curVer.first, i) + distance[curVer.first];
                queue.decreaseKey(i, distBetweenVertexes(curVer.first, i) + distance[curVer.first]);
                pred[i] = curVer.first;
            }
        }
    }

    int pred_temp;

    for (int i = 0; i < getNumVer(); ++i) {
        ways[i].from = index_vertex;
        ways[i].to = i;
        list<int> way_list;
        for (pred_temp = i; pred_temp != -1; pred_temp = pred[pred_temp]) {
            way_list.push_back(pred_temp);
            if (pred[pred_temp] != -1)
                ways[i].dist += distBetweenVertexes(pred_temp, pred[pred_temp]);
        }

        way_list.reverse();

        ways[i].way.resize(way_list.size());
        int j = 0;
        for (int index : way_list) {
            ways[i].way[j] = index;
            ++j;
        }

        way_list.clear();
    }

    return ways;
}


MapOfLocation::MapOfLocation(const std::vector<Vertex> &_vertexes, const std::vector<Edge> &_signature)
        :Graph(_vertexes, _signature), tableOfShortestWay(_vertexes.size()*_vertexes.size()) {
    unsigned int size = getNumVer();
    int start = 0;
    std::vector <WayDescription> FoundWays;

    for (int i = 0; i < size; ++i) {
        FoundWays = findShortWays(vertexes[i].second);
        for (int j = 0; j < FoundWays.size(); ++j) { tableOfShortestWay[start++] = FoundWays[j]; }
    }

}

MapOfLocation::MapOfLocation(const Graph &graph) : Graph(graph), tableOfShortestWay(vertexes.size()*vertexes.size()) {
    unsigned int size = getNumVer();
    int start = 0;
    std::vector <WayDescription> FoundWays;

    for (int i = 0; i < size; ++i) {
        FoundWays = findShortWays(vertexes[i].second);
        for (int j = 0; j < FoundWays.size(); ++j) { tableOfShortestWay[start++] = FoundWays[j]; }
    }

}

WayDescription MapOfLocation::ShortestWayFromTo(int &from, int &to) const {
    //возвращает запись из таблицы, где хранятся уже готовые заготовки путей
    int min = std::min(from, to);
    int max = std::max(from, to);

    for (WayDescription a : tableOfShortestWay)
        if (a.from == min && a.to == max) {
            if (from != min)
                a.reverse();
            return a;
        }

    return {};
}

WayDescription MapOfLocation::FindShortestWay(const Graph::Vertex &ver_from, const Graph::Vertex &ver_to) const {
    int index_from(findVertex(ver_from)), index_to(findVertex(ver_to));
    WayDescription WayGlobalID(ver_from.getName(), ver_to.getName());

    if (index_from == -1 || index_to == -1)
        return WayGlobalID;

    WayDescription WayLocalID = ShortestWayFromTo(index_from, index_to);
    WayGlobalID.way.resize(WayLocalID.way.size());

    for (int i = 0; i < WayLocalID.way.size(); ++i)
        WayGlobalID.way[i] = vertexes[WayLocalID.way[i]].first.getName();

    WayGlobalID.dist = WayLocalID.dist;

    return WayGlobalID;
}

void MapOfLocation::answerOnYourQuestion() const {
    for (auto a : tableOfShortestWay)
        std::cout << a;
}



