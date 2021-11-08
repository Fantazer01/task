//
// Created by oleg on 07.11.2021.
//

#include "MapOfLocation.h"
#include <string>
#include <iostream>


void MapOfLocation::initializationParameters(std::pair<int, int> *setOfVertexes, int *color, int *pred) {
    for (int i = 0; i < vertexes.size(); ++i) {
        setOfVertexes[i].first = vertexes[i].second;
        setOfVertexes[i].second = -1;
        color[i] = 0;
        pred[i] = -1;
    }
}

std::vector<MapOfLocation::WayDescription> MapOfLocation::findShortWays(const int &index_vertex) {
    std::vector<WayDescription> ways;//вектор самых коротких путей от вершины, индекс которой передается, до каждой другой вершины
    //заготовка для алгоритма Дейкстры
    int time = 0;
    std::pair<int, int> setOfVertexes[vertexes.size()];//first - index, second - distance
    int color[vertexes.size()];
    int pred[vertexes.size()];
    int timer[vertexes.size()][2];
    std::pair<int, int> gotTheVertex;

    initializationParameters(setOfVertexes, color, pred);
    PriorityQueue queue(vertexes.size(), setOfVertexes);
    queue.decreaseKey(index_vertex, 0);
    color[gotTheVertex.first] = 1;


    while (!queue.empty()) {
        //std::cout << queue.getHeapSize() << std::endl;
        gotTheVertex = queue.extractMim();

        timer[gotTheVertex.first][0] = time;
        for (int i = 0; i < vertexes.size(); ++i) {
            if (distanceBetweenVertexes(gotTheVertex.first, i) > 0 && color[i] == 0) {
                queue.decreaseKey(i, distanceBetweenVertexes(gotTheVertex.first, i));
                color[i] = 1;
            }
        }

        ++time;
    }

    return ways;
}

MapOfLocation::MapOfLocation(const std::vector<Vertex> &_vertexes, const std::vector<Edge> &_signature)
        :Graph(_vertexes, _signature), tableOfShortestWay(_vertexes.size()*(_vertexes.size()-1)/2) {
    int i, j, size = vertexes.size();
    int start = 0;
    std::vector <WayDescription> FoundWays;

    for (i = 0; i < size; ++i) {
        FoundWays = findShortWays(vertexes[i].second);

        for (j = 0; j < FoundWays.size(); ++j) {
            tableOfShortestWay[start++] = FoundWays[j];
        }
    }

}

MapOfLocation::WayDescription MapOfLocation::ShortestWayFromTo(int &from, int &to) {
    //возвращает запись из таблицы, где хранятся уже готовые заготовки путей
    return MapOfLocation::WayDescription();
}

std::vector<MapOfLocation::Vertex> MapOfLocation::FindShortestWay(const Graph::Vertex &ver1, const Graph::Vertex &ver2) {
    std::vector<Vertex> VertexPath;
    int index1(findVertex(ver1)), index2(findVertex(ver2));

    if (index1 == -1 || index2 == -1)
        return VertexPath;

    WayDescription wayDesc = ShortestWayFromTo(index1, index2);

    VertexPath.resize(wayDesc.way.size());

    for (int index_of_ver : wayDesc.way)
        VertexPath.push_back(vertexes[index_of_ver].first);

    return VertexPath;
}



