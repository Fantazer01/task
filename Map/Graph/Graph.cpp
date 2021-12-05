//
// Created by oleg on 07.11.2021.
//

#include "Graph.h"

std::istream& operator >> (std::istream& input, Graph::Vertex &ver) {
    input >> ver.id;
    return input;
}

std::ostream& operator << (std::ostream& output, const Graph::Vertex &ver) {
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

Graph::Vertex Graph::getVertex(const uint &index) const {
    if (vertexes[index].second == index)
        return Vertex(vertexes[index].first);

    throw std::invalid_argument("vertex don't exist or indexing error");
}

void Graph::initialization(const std::vector<Edge> &_signature) {
    int i, j;

    signature = new int*[numVer];

    for (i = 0; i < numVer; ++i) {
        signature[i] = new int[numVer - i];
        for (j = 0; j < numVer - i; ++j)
            if (i == j + i)
                signature[i][j] = 0;
            else
                signature[i][j] = -1;
    }

    int a, b;
    uint n = _signature.size();

    for (i = 0; i < n; ++i) {
        a = findVertex(_signature[i].ver1);
        b = findVertex(_signature[i].ver2);
        if (a != -1 && b != -1 && a != b)
            signature[std::min(a, b)][std::max(a,b)-std::min(a, b)] = _signature[i].distance;
    }
}

Graph::Graph(const std::vector<Vertex> &_vertexes, const std::vector<Edge> &_signature): numVer(_vertexes.size()), vertexes(numVer) {
    for (int i = 0; i < numVer; ++i)
        vertexes[i] = std::pair<Vertex, int>(_vertexes[i], i);

    initialization(_signature);
}

Graph::Graph(const Graph &graph): numVer(graph.numVer), vertexes(graph.vertexes) {

    if (graph.signature != nullptr) {
        signature = new int*[numVer];

        for (int i = 0; i < numVer; ++i) {
            signature[i] = new int[numVer - i];
            for (int j = 0; j < numVer - i; ++j)
                signature[i][j] = graph.signature[i][j];
        }
    }

}

Graph::Graph(Graph && graph) noexcept: numVer(graph.numVer), vertexes(std::move(graph.vertexes)), signature(graph.signature) {
    graph.signature = nullptr;
}

Graph::~Graph() {
    if (signature != nullptr)
        for (int i = 0; i < numVer; ++i)
            delete [] signature[i];
    delete [] signature;
}

int Graph::distBetweenVertexes(const uint &index1, const uint &index2) const {
    if (index1 >= numVer || index2 >= numVer)
        throw std::invalid_argument("invalid index");

    return signature[std::min(index1, index2)][std::max(index1, index2) - std::min(index1, index2)];
}

Graph& Graph::operator = (const Graph &graph) {
    if (this == &graph)
        return *this;

    if (signature != nullptr)
        for (int i = 0; i < numVer; ++i)
            delete [] signature[i];
    delete [] signature;

    numVer = graph.numVer;
    vertexes.assign(graph.vertexes.begin(), graph.vertexes.end());

    if (graph.signature != nullptr) {
        signature = new int*[numVer];

        for (int i = 0; i < numVer; ++i) {
            signature[i] = new int[numVer - i];
            for (int j = 0; j < numVer - i; ++j)
                signature[i][j] = graph.signature[i][j];
        }
    }

    return *this;
}

int Graph::getConnection(const Vertex &ver1, const Vertex &ver2) const {
    int index1, index2;
    index1 = findVertex(ver1);
    index2 = findVertex(ver2);

    if (index1 < 0 || index2 < 0)
        throw std::invalid_argument("invalid index");

    return distBetweenVertexes(index1, index2);
}

int Graph::getConnection(const uint &id1, const uint &id2) const {
    int index1, index2;
    index1 = findVertex(Vertex(id1));
    index2 = findVertex(Vertex(id2));

    if (index1 < 0 || index2 < 0)
        throw std::invalid_argument("invalid index");

    return distBetweenVertexes(index1, index2);
}

int Graph::getConnection(const const_iteratorV &it1, const const_iteratorV &it2) const {
    return distBetweenVertexes(it1-vertexes.cbegin(), it2-vertexes.cbegin());
}

std::ostream& Graph::put(std::ostream &output) const {
    for (int i = 0; i < numVer; ++i)
        for (int j = 0; j < numVer - i; ++j)
            if (signature[i][j] > 0)
                output << getVertex(i) << "--" << getVertex(j+i) << "\n";

    return output;
}

std::ostream& operator << (std::ostream& output, Graph &graph) {
    int i, j, k;

    output << "Vertexes:" << std::endl;
    for (i = 0; i < graph.numVer; ++i)
        output << "global id: " << graph.vertexes[i].first << ", local id: " << graph.vertexes[i].second<< std::endl;

    for (i = 0; i < graph.numVer; ++i) {
        output << "signature(" << graph.getVertex(i) << "[" << i << "]): ";
        for (j = 0, k = 0; j < graph.numVer; ++j) {
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


