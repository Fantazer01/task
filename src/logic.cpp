//
// Created by oleg on 15.11.2021.
//


#include "logic.h"
#include <fstream>
#include <vector>



Graph readGraph(std::istream &input) {
    using namespace std;
    vector<Graph::Vertex> vertexes;
    vector<Graph::Edge> edges;
    Graph::Vertex ver;
    Graph::Edge edge;
    char c;

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

    for (input >> c; !input.eof(); input >> c) {
        if (c == '(') {
            input >> edge.ver1;
            if (input.good() && input.get(c).good() && c == ':') {
                input >> edge.ver2;
                if (input.good() && input.get(c).good() && c == '|') {
                    input >> edge.distance;
                    if (input.good()) {
                        edges.push_back(edge);
                        std::cout << edge.ver1 <<" " << edge.ver2 << " " << edge.distance << std::endl;
                    }

                }
            }
            input.clear();
        }

    }

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
