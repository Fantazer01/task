#include <utility>
#include <vector>
#include <iostream>
#include <string>

//
// Created by oleg on 07.11.2021.
//

#ifndef TASK1_GRAPH_H
#define TASK1_GRAPH_H


class Graph {
public:
    class Vertex {
        unsigned int id;
    public:
        Vertex():id(0) {}
        explicit Vertex(unsigned int _id): id(_id) {}
        unsigned int getName() const { return id; }
        void setName(unsigned int _id) { id = _id; };

        bool operator == (const Vertex &ver2) const { return id == ver2.id; }

        friend std::istream& operator >> (std::istream&, Vertex &);
        friend std::ostream& operator << (std::ostream&, Vertex &);
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
    int distBetweenVertexes(const int &index1, const int &index2);
public:
    Graph():signature(nullptr) {}
    Graph(const std::vector<Vertex> &_vertexes, const std::vector<Edge> &_signature);
    ~Graph();

    int findVertex(const Vertex &ver) const;

    friend std::ostream& operator << (std::ostream&, Graph &);
};


#endif //TASK1_GRAPH_H
