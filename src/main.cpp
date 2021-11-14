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
            {Graph::Vertex("1"), Graph::Vertex("2"), 1},
            {Graph::Vertex("1"), Graph::Vertex("3"), 2},
            {Graph::Vertex("2"), Graph::Vertex("3"), 5},
            {Graph::Vertex("2"), Graph::Vertex("Warehouse"), 5},
            {Graph::Vertex("3"), Graph::Vertex("Warehouse"), 5}
    };
    /*
    std::pair<int,int> a[] = {
            {1, 1},
            {2, 2},
            {3, 3}
    };
    PriorityQueue queue(3, a);
    std::cout << queue.getHeapSize() << std::endl;
    std::cout << queue.size() << std::endl;*/
    MapOfLocation map(vertexes, signature);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
