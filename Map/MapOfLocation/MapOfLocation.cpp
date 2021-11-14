//
// Created by oleg on 07.11.2021.
//

#include "MapOfLocation.h"
#include <iostream>
#include <list>


void MapOfLocation::initializationParameters(std::pair<int, int> *setOfVertexes, int *pred, int *distance) {
    for (int i = 0; i < vertexes.size(); ++i) {
        setOfVertexes[i].first = vertexes[i].second;
        setOfVertexes[i].second = -1;
        pred[i] = -1;
        distance[i] = -1;
    }
}

std::vector<MapOfLocation::WayDescription> MapOfLocation::findShortWays2(const int &index_vertex) {
    using namespace std;

    vector<WayDescription> ways(vertexes.size());//вектор самых коротких путей от вершины, индекс которой передается, до каждой другой вершины
    //заготовка для алгоритма Дейкстры
    pair<int, int> setOfVertexes[vertexes.size()];//first - index, second - distance
    int pred[vertexes.size()];
    int distance[vertexes.size()];
    pair<int, int> curVer;

    initializationParameters(setOfVertexes, pred, distance);
    PriorityQueue queue(vertexes.size(), setOfVertexes);
    queue.decreaseKey(index_vertex, 0);


    while (!queue.empty()) {
        curVer = queue.extractMim();
        distance[curVer.first] = curVer.second;

        for (int i = 0; i < vertexes.size(); ++i) {
            if (distBetweenVertexes(curVer.first, i) < 0)
                continue;
            if (distance[i] < 0 || distance[i] > distBetweenVertexes(curVer.first, i) + distance[curVer.first]) {
                distance[i] = distBetweenVertexes(curVer.first, i) + distance[curVer.first];
                queue.decreaseKey(i, distBetweenVertexes(curVer.first, i) + distance[curVer.first]);
                pred[i] = curVer.first;
            }
        }
    }

    int pred_temp = -1;

    for (int i = 0; i < vertexes.size(); ++i) {
        ways[i].from = index_vertex;
        ways[i].to = i;
        list<int> way_list;
        for (pred_temp = i; pred_temp != -1; pred_temp = pred[pred_temp]) {
            way_list.push_back(pred_temp);
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
    int i, j, size = vertexes.size();
    int start = 0;
    std::vector <WayDescription> FoundWays;

    for (i = 0; i < size; ++i) {
        FoundWays = findShortWays2(vertexes[i].second);
        for (WayDescription a : FoundWays) {
            std::cout << "from: " << a.from << " to: " << a.to << " way: ";
            for (int b : a.way)
                std::cout << b << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
        for (j = 0; j < FoundWays.size(); ++j) {
            tableOfShortestWay[start++] = FoundWays[j];
        }
    }

}

MapOfLocation::WayDescription MapOfLocation::ShortestWayFromTo(int &from, int &to) {
    //возвращает запись из таблицы, где хранятся уже готовые заготовки путей
    for (auto a : tableOfShortestWay)
        if (a.from == from && a.to == to)
            return a;
    return MapOfLocation::WayDescription();
}

std::vector<MapOfLocation::Vertex> MapOfLocation::FindShortestWay(const Graph::Vertex &ver1, const Graph::Vertex &ver2) {
    std::vector<Vertex> VertexPath;
    int index1(findVertex(ver1)), index2(findVertex(ver2));

    if (index1 == -1 || index2 == -1)
        return VertexPath;

    WayDescription wayDesc = ShortestWayFromTo(index1, index2);

    VertexPath.resize(wayDesc.way.size());

    for (int i = 0; i < wayDesc.way.size(); ++i)
        VertexPath[i] = vertexes[wayDesc.way[i]].first;

    return VertexPath;
}



