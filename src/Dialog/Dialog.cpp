//
// Created by oleg on 17.11.2021.
//

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include "Dialog.h"

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

MapOfLocation initMap(const int &argc, char* argv[]) {
    char default_name[] = "GraphList.txt";
    char *filename = default_name;

    if (argc > 1)
        filename = argv[1];

    std::ifstream file(filename);

    if (file.is_open())
        return MapOfLocation(readGraph(file));
    else
        return {};
}

void setMap(MapOfLocation &map) {
    char filename[81];
    std::cout << "Enter name file, where you want to read graph: ";
    std::cin >> std::setw(81) >> filename;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::ifstream file(filename);

    if (file.is_open()) {
        map = MapOfLocation(readGraph(file));
        std::cout << "File was read successfully" << std::endl;
    } else
        std::cout << "File isn't found" << std::endl;
}

void putGraph(MapOfLocation &map) {
    std::cout << map;

    std::ofstream file("putGraph.gv");
    file << "graph G {\n";
    map.put(file);
    file << "}\n";
    file.close();
    system("dot -Tpng putGraph.gv -o picture.png && sxiv picture.png");
}
