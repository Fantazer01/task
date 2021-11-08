#include <iostream>
#include "Graph.h"
#include "MapOfLocation.h"

int main() {
    using namespace std;

    vector<Graph::Vertex> vertexes =
    {
             Graph::Vertex("1"),
             Graph::Vertex("2"),
             Graph::Vertex("3"),
             Graph::Vertex("Warehouse")
    };

    vector<Graph::Edge> signature =
    {
            {Graph::Vertex("1"), Graph::Vertex("2"), 5},
            {Graph::Vertex("1"), Graph::Vertex("3"), 5},
            {Graph::Vertex("2"), Graph::Vertex("3"), 5},
            {Graph::Vertex("2"), Graph::Vertex("Warehouse"), 5},
            {Graph::Vertex("3"), Graph::Vertex("Warehouse"), 5}
    };

    MapOfLocation map(vertexes, signature);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
