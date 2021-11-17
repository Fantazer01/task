//
// Created by oleg on 28.09.2021.
//

#include <iostream>

void skip_to_int() {
    if (std::cin.fail()) {
        std::cin.clear();
        for (char ch; std::cin >> ch;) {
            if (std::isdigit(ch) || ch == '-') {
                std::cin.unget();
                return;
            }
        }
    }

    throw "Ввода нет";
}

void getNum(int &num) {
    while (true) {
        if (std::cin >> num)
            return;
        else
            skip_to_int();
    }
}

void getNum(double &num) {
    while (true) {
        if (std::cin >> num)
            return;
        else
            skip_to_int();
    }
}

void getNum(int &num, char* const str) {
    while (true) {
        if (std::cin >> num)
            return;
        else {
            std::cout << str << std::endl;
            skip_to_int();
        }

    }
}

void getNum(double &num, char* const str) {
    while (true) {
        if (std::cin >> num)
            return;
        else {
            std::cout << str << std::endl;
            skip_to_int();
        }

    }
}
