//
// Created by oleg on 17.11.2021.
//

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include "Dialog.h"

int menu() {
    const char *menu_msgs[] =
            {
                    "1. Настроить граф",
                    "2. Вывести граф",
                    "3. Указать id склада",
                    "4. Вывести id склада",
                    "5. Добавить заявку",
                    "6. Вывести список заявок",
                    "7. Расчитать маршруты",
                    "0. Выход"
            };

    const int size_menu_msgs = sizeof(menu_msgs) / sizeof(*menu_msgs);

    for(auto & menu_msg : menu_msgs)
        std::cout << menu_msg << std::endl;

    return size_menu_msgs;
}

int dialog() {
    int numOfStations, rc;
    std::string err_msg = "";

    //system("clear");
    numOfStations = menu();

    do {
        std::cout << err_msg;
        err_msg = "enter the number corresponding to one of the menu items\n";
        try{
            getNum(rc);
        } catch (const char err[]) {
            std::cout << "End of file" << std::endl;
            return 0;
        }
    } while(rc >= numOfStations || rc < 0);
    //system("clear");
    return rc;
}

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

void addOrder(std::list<Order> &orders) {
    int id, num;

    std::cout << "Enter order data (id point and number of one): ";
    getNum(id);
    getNum(num);

    Order order(id, num);

    std::list<Order>::iterator p;

    for (p = orders.begin(); p != orders.end(); ++p)
        if (order.getId() == p->getId()) {
            p->add(order.getNumber());
            return;
        }

    orders.push_back(order);
}

void printOrders(const std::list<Order> &orders) {
    std::cout << "List of orders (id point and number of one):\n";

    if (orders.size() == 0) {
        std::cout << "Empty" << std::endl;
        return;
    }

    for (const Order &a : orders)
        std::cout << a << std::endl;
}

void calculatePrintRoutes
    (const MapOfLocation &Map, const int &id_WH, std::list<Order> orders, const std::vector<Truck> &trucks) {
    std::list<Route> routes;
    std::list<Truck> unoccupiedTrucks;
    Route route;
    int counter = 0;

    for (const Truck &a : trucks)
        unoccupiedTrucks.push_back(a);

    //std::cout << "\ninfo\n\n";
    while (!orders.empty() && !unoccupiedTrucks.empty()) {
        routes.push_back(calculateRoute(counter, Map, id_WH, orders, unoccupiedTrucks));
        ++counter;
    }

    /*
    for (Route a : routes) {
        std::cout << "id: " << a.getId() << ", id of truck: " << a.getIdTruck() << " \nways:\n";
        std::list<std::pair<WayDescription, Order>> b = a.getWays();
        for (auto c : b) {
            std::cout << c.first;
        }
        std::cout << "\nnew\n";
    }
     */
    //std::cout << "\n\ninfo\n\n";

}

