#include <iostream>
#include <cstring>
#include <unistd.h>
#include "LiteSH.hpp"

using namespace std;

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Недостаточно аргументов для информации введите --help|-h\n";
        return 0;
    }


    if (RecvSignal(SIGINT) == 1) {
        cout << "Ошибка получения сигнала" << endl;
    }
    sleep(60);

    if (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")) {
        cout << "Авторы: Дак Михаил, Лозовой Владислав, Степанов Владислав" << endl
             << "Программа предназначена для работы с файловой системой" << endl
             << "--help || -h - Вывод информации о программе и её функциях" << endl
             << "FileManager - Вызов программы Managing_the_file_system" << endl
             << "CreateProcess - Порождение процесса " << endl
             << "CreateDaemon - Перевод процесса в фоновый режим" << endl
             << "SendSignal - Отправка сигнала процессу" << endl
             << "RecvSignal - Получение сигнала от процесса";
        ifstream signals("signals.txt");
        string SigName;
        cout << "Доступные номера сигналов" << endl;
        for (int i = 1; getline(signals, SigName); i++) {
            cout << "\E[36m" << i << " - ";
            cout << "\E[39m";
            cout << SigName << endl;
        }
        signals.close();
//    } else if (!strcmp(argv[1], "FileManager")) {
//        CreateProcess("/home/misha/Labs/Operation-System/Program");
    } else if (!strcmp(argv[1], "CreateProcess")) {
        if (argc < 3) {
            cout << "Недостаточно аргументов" << endl;
            return 0;
        }

        if (CreateProcess(argv[2]) == 1) {
            cout << "Не создаётся процесс";
        }
    } else if (!strcmp(argv[1], "CreateDaemon")) {
        if (argc < 3) {
            cout << "Недостаточно аргументов" << endl;
            return 0;
        }
        if (CreateDaemon(argv[2]) == 1) {
            cout << "Не создаётся демон";
        }

    } else if (!strcmp(argv[1], "SendSignal")) {
        pid_t pid, signum;
        cout << "Введите pid: ";
        cin >> pid;
        cout << "Введите сигнал для отправки: ";
        cin >> signum;
        if (SendSignal(pid, signum) == 1) {
            cout << "Ошибка отправки сигнала" << endl;
        }
    }

    return 0;
}
