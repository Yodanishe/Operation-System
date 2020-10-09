#include <iostream>
#include "commands.hpp"
#include <cstring>

using namespace std;

int main(int argc, char **argv) {

    if (argc < 2) {
        cout << "Недостаточно аргументов для информации введите --help|-h\n";
        return 0;
    }

    if (!strcmp(argv[1], "--help") || !strcmp(argv[1],"-h")) {
        cout << "Авторы: Дак Михаил, Лозовой Владислав, Степанов Владислав" << endl
        << "Программа предназначена для работы с файловой системой" << endl
        << "--help || -h Вывод информации о программе и её функциях" << endl
        << "--move || -m ./file.txt ./builds/file.txt - Перемещение файла в нужную директорию" << endl
        << "--copy || -c ./file.txt ./builds/file.txt - Копирование файла в нужную директорию" << endl
        << "--delete || -d ./file.txt Удалить файл из текущей директории" << endl
        ;
    } else if (!strcmp(argv[1], "--move") || !strcmp(argv[1],"-m")) {
        if (argc < 4) {
            cout << stderr << "Недостаточно аргументов" << endl;
            return 0;
        }

        move(argv[2], argv[3]);
    } else if (!strcmp(argv[1], "--copy") || !strcmp(argv[1],"-c")) {
        if (argc < 4) {
            cout << stderr << "Недостаточно аргументов" << endl;
            return 0;
        }

        copy(argv[2],argv[3]);
    } else if (!strcmp(argv[1], "--delete") || !strcmp(argv[1],"-d")) {
            if (argc < 3) {
                cout << stderr << "Недостаточно аргументов" << endl;
            }

        deleting(argv[2]);
    }

    return 0;
}
