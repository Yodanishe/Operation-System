#include <iostream>
#include "commands.hpp"
#include <cstring>

using namespace std;

int main(int argc, char **argv) {

    if (argc < 2) {
        cout << "Недостаточно аргументов для информации введите --help|-h\n";
        return 0;
    }

    if (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")) {
        cout << "Авторы: Дак Михаил, Лозовой Владислав, Степанов Владислав" << endl
             << "Программа предназначена для работы с файловой системой" << endl
             << "--help || -h Вывод информации о программе и её функциях" << endl
             << "--MV ./fileName.txt ./builds/fileName.txt - Перемещение файла в нужную директорию" << endl
             << "--CP ./fileName.txt ./builds/fileName.txt - Копирование файла в нужную директорию" << endl
             << "--ls ./directoryName - Отображение всех файлов в директории" << endl
             << "--RM ./fileName.txt - Удалить файл из текущей директории" << endl
             << "--SizeFile ./fileName.txt - Размер файла" << endl
             << "--SizeDir ./directoryName/ - Размер директории" << endl
             << "--procfs - Отображение всех процессов из файловой системы procfs" << endl;
    } else if (!strcmp(argv[1], "--MV")) {
        if (argc < 4) {
            cout << stderr << "Недостаточно аргументов" << endl;
            return 0;
        }

        MV(argv[2], argv[3]);
    } else if (!strcmp(argv[1], "--CP")) {
        if (argc < 4) {
            cout << stderr << "Недостаточно аргументов" << endl;
            return 0;
        }

        CP(argv[2], argv[3]);
    } else if (!strcmp(argv[1], "--RM")) {
        if (argc < 3) {
            cout << stderr << "Недостаточно аргументов" << endl;
        }

        RM(argv[2]);
    } else if (!strcmp(argv[1], "--SizeFile")) {
        if (argc < 3) {
            cout << stderr << "Недостаточно аргументов" << endl;
        }

        SizeFile(argv[2]);
    } else if (!strcmp(argv[1], "--SizeDir")) {
        if (argc < 3) {
            cout << stderr << "Недостаточно аргументов" << endl;
        }

        SizeDir(argv[2]);
    } else if (!strcmp(argv[1], "--ls")) {
        if (argc < 3) {
            cout << stderr << "Недостаточно аргументов" << endl;
        }

        ls(argv[2]);
    } else if (!strcmp(argv[1], "--procfs")) {
        mapping_process();
    }

    return 0;
}
