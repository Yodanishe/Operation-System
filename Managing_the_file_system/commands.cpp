#include "commands.hpp"
#include <cstdio>
#include <iostream>

using namespace std;

int move(char *oldpath, char *newpath) {
    cout << "Перемещение файла из " << oldpath << "В" << newpath;
    if (rename(oldpath, newpath) == -1) {
        cout << stderr << "Ошибка перемещения файла" << endl << endl;
        return 1;
    }

    return 0;
}