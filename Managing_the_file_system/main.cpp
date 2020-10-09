#include <iostream>
#include "commands.hpp"
#include <cstring>

using namespace std;

int main(int argc, char **argv) {

    if (argc < 2) {
        cout << "Недостаточно аргументов для информации введите --help|-h\n";
    }

    if (!strcmp(argv[1], "--help") || !strcmp(argv[1],"-h")) {
        cout << "Авторы: Дак Михаил, Лозовой Владислав, Степанов Владислав" << endl
        << "Программа предназначена для работы с файловой системой" << endl
        << "--help || -h Вывод информации о программе и её функциях" << endl
        << "--move ./example.txt ./builds/example.txt || -m ./example.txt ./builds/example.txt " << endl
        ;
    } else if (!strcmp(argv[1], "--move") || !strcmp(argv[1],"-m")) {
        if (argc < 4) {
            cout << stderr << "Недостаточно аргументов" << endl;
            return 0;
        }

        move(argv[2], argv[3]);
    }
//    else if (!strcmp(argv[1], "--copy") || !strcmp(argv[1],"-c")) {
//        if (argc < 4) {
//            cout << stderr << "Недостаточно аргументов" << endl;
//            return 0;
//        }
//
//        copy(argv[2],argv[3]);
//    }

    return 0;
}
