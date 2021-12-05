//
// Created by oleg on 06.12.2021.
//

#include <iostream>
#include <string>
#include "Dialog.h"

int menu()
{
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

int dialog()
{
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

