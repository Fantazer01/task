//
// Created by oleg on 07.11.2021.
//

#include "Graph.h"

std::istream& operator >> (std::istream& input, Graph::Vertex &ver) {
    input >> ver.id;
    return input;
}

std::ostream& operator << (std::ostream& output, Graph::Vertex &ver) {
    output << ver.id;
    return output;
}

int Graph::findVertex(const Vertex &ver) const {
    unsigned int size = vertexes.size();

    for (int i = 0; i < size; ++i)
        if (vertexes[i].first == ver)
            return i;

    return -1;
}

void Graph::initialization(const unsigned int &size, const std::vector<Edge> &_signature) {
    int i, j;

    signature = new int*[size];

    for (i = 0; i < size; ++i) {
        signature[i] = new int[size - i];
        for (j = 0; j < size - i; ++j)
            if (i == j + i)
                signature[i][j] = 0;
            else
                signature[i][j] = -1;
    }

    int a, b, n = _signature.size();

    for (i = 0; i < n; ++i) {
        a = findVertex(_signature[i].ver1);
        b = findVertex(_signature[i].ver2);
        if (a != -1 && b != -1 && a != b)
            signature[std::min(a, b)][std::max(a,b)] = _signature[i].distance;
    }
}

Graph::Graph(const std::vector<Vertex> &_vertexes, const std::vector<Edge> &_signature): vertexes(_vertexes.size()) {
    for (int i = 0; i < vertexes.size(); ++i)
        vertexes[i] = std::pair<Vertex, int>(_vertexes[i], i);

    initialization(vertexes.size(), _signature);
}

Graph::~Graph() {
    unsigned int size = vertexes.size();

    for (int i = 0; i < size; ++i)
        delete [] signature[i];
    delete [] signature;
}

int Graph::distBetweenVertexes(const int &index1, const int &index2) {
    if (index1 >= vertexes.size() || index2 >= vertexes.size() || index1 < 0 || index2 < 0)
        throw std::invalid_argument("invalid index");

    return signature[std::min(index1, index2)][std::max(index1, index2) - std::min(index1, index2)];
}

std::ostream& operator << (std::ostream& output, Graph &graph) {
    int i, j, k;
    unsigned int size = graph.vertexes.size();

    output << "Vertexes:" << std::endl;
    for (i = 0; i < size; ++i)
        output << "global id: " << graph.vertexes[i].first << ", local id: " << graph.vertexes[i].second<< std::endl;

    for (i = 0; i < size; ++i) {
        output << "signature(" << i << "): ";
        for (j = 0, k = 0; j < size; ++j) {
            if (graph.distBetweenVertexes(i, j) != -1 && i != j) {
                output << j << "(" << graph.distBetweenVertexes(i, j) << ") ";
                ++k;
            }
        }
        if (k == 0)
            output << "nothing";
        output << std::endl;
    }

    return output;
}

