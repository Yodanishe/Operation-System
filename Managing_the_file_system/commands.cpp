#include "commands.hpp"
#include <cstdio>
#include <iostream>

using namespace std;

int move(char *oldpath, char *newpath) {
    cout << "Перемещение файла из " << oldpath << " В " << newpath << endl;
    if (rename(oldpath, newpath) == -1) {
        cout <<"Ошибка перемещения файла" << endl << endl;
        return 1;
    }

    return 0;
}

int copy(char *oldpath, char *newpath) {
    cout << "Копироване файла"<< endl;

    FILE *old = fopen(oldpath, "r");
    if (!old) {
        cout << "Файл отсутствует" << endl;
        return 1;
    }
    FILE *update = fopen(newpath, "wr");
    if (!update) {
        cout << "Ошибка создания файла" << endl;
    }

    char temp;
    while ((temp = getc(old)) != EOF) {
        fputc(temp,update);
    }
    fclose(old);
    fclose(update);

    return 0;
}

int deleting(char *filename) {
    cout << "Удаление файла" << filename << endl;
    if (remove(filename) == -1) {
        cout << "Ошибка удаления файла" << endl;
        return 1;
    }
    return 0;
}