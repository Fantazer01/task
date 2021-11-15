#include <iostream>
#include "Graph.h"
#include "MapOfLocation.h"
#include "logic.h"

int main(int argc, char* argv[]) {
    using namespace std;

    vector<Graph::Vertex> vertexes =
    {
             Graph::Vertex(1),
             Graph::Vertex(2),
             Graph::Vertex(3),
             Graph::Vertex(999)
    };

    vector<Graph::Edge> signature =
    {
            {Graph::Vertex(1), Graph::Vertex(2), 1},
            {Graph::Vertex(1), Graph::Vertex(3), 2},
            {Graph::Vertex(2), Graph::Vertex(3), 5},
            {Graph::Vertex(2), Graph::Vertex(999), 5},
            {Graph::Vertex(3), Graph::Vertex(999), 5}
    };
    char *filename = nullptr;
    if (argc > 1)
        filename = argv[1];

    Graph graph = initGraph(filename);
    cout << graph << endl;
    /*
    MapOfLocation map(vertexes, signature);
    vector<MapOfLocation::Vertex> way = map.FindShortestWay(Graph::Vertex("Warehouse"), Graph::Vertex("1"));
    for (auto a : way) {
        cout << a.getName() << " ";
    }
    cout << endl;*/
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
