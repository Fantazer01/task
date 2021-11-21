#include <utility>
#include <vector>
#include <iostream>

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
        friend std::ostream& operator << (std::ostream&, const Vertex &);
    };

    struct Edge {
        Vertex ver1;
        Vertex ver2;
        int distance;
    };

private:
    unsigned int numVer;
    int **signature;//signature
protected:
    std::vector<std::pair<Vertex, int>> vertexes;//vertexes

    //helper methods
    void initialization(const std::vector<Edge> &_signature);
    int distBetweenVertexes(const int &index1, const int &index2);
    int findVertex(const Vertex &ver) const;
    Vertex getVertex(const int &index);
public:
    Graph(): numVer(0), signature(nullptr) {}
    Graph(const std::vector<Vertex> &_vertexes, const std::vector<Edge> &_signature);
    Graph(const Graph &graph);
    Graph(Graph && graph) noexcept ;
    ~Graph();

    unsigned int getNumVer() const { return numVer; }

    Graph& operator = (const Graph &);

    friend std::ostream& operator << (std::ostream&, Graph &);
};


#endif //TASK1_GRAPH_H
