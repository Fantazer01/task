//
// Created by oleg on 15.11.2021.
//


#include "logic.h"
#include <fstream>
#include <vector>

void readVer(std::istream &input, std::vector<Graph::Vertex> &vertexes) {
    char c;
    Graph::Vertex ver;

    for (input >> c; !input.eof() && c != '}'; input >> c) {
        if (c == '{') {
            while (!input.fail()) {
                input >> ver;
                if (!input.fail())
                    vertexes.push_back(ver);
            }
            input.clear();
        }
    }
}

void readEdge(std::istream &input, std::vector<Graph::Edge> &edges) {
    char c;
    Graph::Edge edge;

    for (input >> c; !input.eof(); input >> c) {
        if (c == '(') {
            input >> edge.ver1;
            if (input.good() && input.get(c).good() && c == ':') {
                input >> edge.ver2;
                if (input.good() && input.get(c).good() && c == '|') {
                    input >> edge.distance;
                    if (input.good())
                        edges.push_back(edge);
                }
            }
            input.clear();
        }
    }
}

Graph readGraph(std::istream &input) {
    using namespace std;
    vector<Graph::Vertex> vertexes;
    vector<Graph::Edge> edges;

    readVer(input, vertexes);

    readEdge(input, edges);

    return Graph(vertexes, edges);
}

Graph initGraph(char *filename) {
    char default_name[] = "GraphList.txt";
    if (filename == nullptr) { filename = default_name; }
    std::ifstream file(filename);

    if (file.is_open())
        return readGraph(file);
    else
        return {};
}
