//
// Created by oleg on 17.11.2021.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Dialog.h"
#include "LabTools.h"

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

MapOfLocation initMap(char *filename) {
    char default_name[] = "GraphList.txt";
    if (filename == nullptr) { filename = default_name; }
    std::ifstream file(filename);

    if (file.is_open())
        return MapOfLocation(readGraph(file));
    else
        return {};
}

int menu() {
    const char *menu_msgs[] =
            {
                    "1. Настроить граф",
                    "2. Вывести граф",
                    "3. Указать id склада",
                    "4. Добавить заявку",
                    "5. Расчитать маршруты",
                    "0. Выход"
            };

    const int size_menu_msgs = sizeof(menu_msgs) / sizeof(*menu_msgs);

    for(auto & menu_msg : menu_msgs)
        std::cout << menu_msg << std::endl;

    return size_menu_msgs;
}

int dialog() {
    int numOfStations, rc;

    numOfStations = menu();

    do {
        try{
            getNum(rc);
        } catch (const char err[]) {
            std::cout << "End of file" << std::endl;
            return 0;
        }
    } while(rc > numOfStations || rc < 0);
    system("clear");
    return rc;
}
