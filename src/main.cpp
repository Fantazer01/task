#include <iostream>
#include "Dialog.h"


int main(int argc, char* argv[]) {
    using namespace std;
    //создаем карту
    MapOfLocation map = initMap(argc, argv);
    //задаем доступные нам машины
    vector<Truck> trucks = {
            {0, 8, 10},
            {1, 8, 10},
            {2, 8, 10}
    };
    //создали список заказов
    list<Order> orders;
    int id_WH = 0;

    int rc;
    while ((rc = dialog()) != 0) {
        switch(rc)
        {
            case 1:
                setMap(map);//настроить граф
                break;
            case 2:
                putGraph(map);//вывести граф
                break;
            case 3:
                cout << "Enter id warehouse: ";//указать id склада
                getNum(id_WH);
                break;
            case 4:
                cout << "Id warehouse: " << id_WH << endl;
                break;
            case 5:
                addOrder(orders);//добавить заявки
                break;
            case 6:
                printOrders(orders);//вывести заявки
                break;
            case 7:
                calculatePrintRoutes(map, id_WH, orders, trucks);//расчитать маршруты
                break;
            default:
                break;
        }
        cin.get();
        cin.get();
    }

    return 0;
}
