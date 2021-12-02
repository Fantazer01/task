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
        unsigned int getID() const { return id; }
        void setID(unsigned int _id) { id = _id; }

        bool operator == (const Vertex &ver2) const { return id == ver2.id; }
        bool operator != (const Vertex &ver2) const { return id != ver2.id; }

        friend std::istream& operator >> (std::istream&, Vertex &);
        friend std::ostream& operator << (std::ostream&, const Vertex &);
    };

    struct Edge {
        Vertex ver1;
        Vertex ver2;
        int distance;
    };

    typedef std::vector<std::pair<Vertex, uint>>::const_iterator const_iteratorV;

private:
    unsigned int numVer;
    int **signature;//signature
    std::vector<std::pair<Vertex, uint>> vertexes;//vertexes

    //helper methods
    void initialization(const std::vector<Edge> &_signature);
protected:
    //helper methods
    int distBetweenVertexes(const uint &index1, const uint &index2);
    int findVertex(const Vertex &ver) const;
    Vertex getVertex(const uint &index) const;
public:
    Graph(): numVer(0), signature(nullptr) {}
    Graph(const std::vector<Vertex> &_vertexes, const std::vector<Edge> &_signature);
    Graph(const Graph &graph);
    Graph(Graph && graph) noexcept ;
    ~Graph();

    Graph& operator = (const Graph &);

    unsigned int getNumVer() const { return numVer; }
    const_iteratorV begin() const { return vertexes.cbegin(); }
    const_iteratorV end() const { return vertexes.cend(); }
    int getConnection(const Vertex &ver1, const Vertex &ver2);
    int getConnection(const uint &id1, const uint &id2);
    int getConnection(const const_iteratorV &it1, const const_iteratorV &it2);

    std::ostream& put(std::ostream&) const;

    friend std::ostream& operator << (std::ostream&, Graph &);
};


#endif //TASK1_GRAPH_H
