#include <iostream>
#include "Dialog.h"


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
 * vector<MapOfLocation::Vertex> way = map.FindShortestWay(Graph::Vertex(0), Graph::Vertex(1));
    printWay(way);

    way = map.FindShortestWay(Graph::Vertex(1), Graph::Vertex(0));
    printWay(way);
 */

void printWay(std::vector<MapOfLocation::Vertex> &way) {
    for (auto a : way)
        std::cout << a.getName() << " ";
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    using namespace std;

    char *filename = nullptr;
    if (argc > 1)
        filename = argv[1];

    MapOfLocation map = initMap(filename);
    vector<Order> order;
    int id_WH = 0;


    int rc;
    while ((rc = dialog()) != 0) {
        switch(rc)
        {
            case 1:
                setMap(map);//настроить граф
                break;
            case 2:
                cout << map;//вывести граф
                break;
            case 3:
                cout << "Enter id warehouse: ";//указать id склада
                getNum(id_WH);
                break;
            case 4:
                //добавить заявки
                break;
            case 5:
                //расчитать маршруты
                break;
        }
        std::cin.get();
        std::cin.get();
        system("clear");
    }

    return 0;
}
