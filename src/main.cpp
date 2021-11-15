#include <iostream>
#include "Graph.h"
#include "MapOfLocation.h"
#include "logic.h"

/*
 *     vector<Graph::Vertex> vertexes =
    {
             Graph::Vertex(1),
             Graph::Vertex(2),
             Graph::Vertex(3),
             Graph::Vertex(0)
    };

    vector<Graph::Edge> signature =
    {
            {Graph::Vertex(1), Graph::Vertex(2), 4},
            {Graph::Vertex(1), Graph::Vertex(3), 1},
            {Graph::Vertex(2), Graph::Vertex(3), 2},
            {Graph::Vertex(2), Graph::Vertex(0), 4},
            {Graph::Vertex(3), Graph::Vertex(0), 8}
    };

 *
 */

int main(int argc, char* argv[]) {
    using namespace std;

    char *filename = nullptr;
    if (argc > 1)
        filename = argv[1];

    //Graph graph = initGraph(filename);
    //cout << graph << endl;

    MapOfLocation map = initMap(filename);
    cout << map;
    vector<MapOfLocation::Vertex> way = map.FindShortestWay(Graph::Vertex(0), Graph::Vertex(1));
    for (auto a : way) {
        cout << a.getName() << " ";
    }
    cout << endl;
    way = map.FindShortestWay(Graph::Vertex(1), Graph::Vertex(0));
    for (auto a : way) {
        cout << a.getName() << " ";
    }
    cout << endl;

    return 0;
}
