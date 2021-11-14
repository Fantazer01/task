#include <utility>
#include <vector>
#include <string>

//
// Created by oleg on 07.11.2021.
//

#ifndef TASK1_GRAPH_H
#define TASK1_GRAPH_H


class Graph {
public:
    class Vertex {
        std::string name;
    public:
        Vertex() = default;
        explicit Vertex(std::string _name): name(std::move(_name)) {}
        std::string getName() const {return name;}
        void setName(std::string _name) {name = std::move(_name);};
    };

    struct Edge {
        Vertex ver1;
        Vertex ver2;
        int distance;
    };
protected:
    std::vector<std::pair<Vertex, int>> vertexes;//vertexes
    int **signature{};//signature
    //helper methods
    void initialization(const int &size, const std::vector<Edge> &_signature);
    int distanceBetweenVertexes(const int &index1, const int &index2);
public:
    Graph():signature(nullptr) {}
    Graph(const std::vector<Vertex> &_vertexes, const std::vector<Edge> &_signature);
    ~Graph();

    int findVertex(const Vertex &ver) const;
};


#endif //TASK1_GRAPH_H
