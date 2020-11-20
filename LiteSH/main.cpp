#include <iostream>
#include <cstring>
#include <dlfcn.h>
#include "LiteSH.hpp"

using namespace std;

int main(int argc, char **argv) {
//    char *error;
//    void *handle = dlopen("/home/misha/Labs/Operation-System/LiteSH/libs/libinfo.so", RTLD_LAZY);
//    if (!handle) {
//        fputs (dlerror(), stderr);
//        return 1;
//    }
//
//    if ((error = dlerror()) != NULL) {
//        fprintf (stderr, "%s\n", error);
//        return 1;
//    }

//    if (RecvSignal(SIGINT) == 1) {
//        cout << "Ошибка получения сигнала" << endl;
//    }
//    sleep(60);

    int selection = 0;
    char *command = new char[100];
    cout << "Write command to server: " << endl;
    cin >> command;

    selection = NetWorkClient(command);
//    cout << endl;

    if (selection == 1) {
        char *name = new char[100];
        cout << "Write Process name: " << endl;
        cin >> name;

        if (CreateProcess(name) == 1) {
            cout << "Не создаётся процесс";
        }
        delete[]name;
    } else if (selection == 2) {
        char *name = new char[100];
        cout << "Write Process name: " << endl;
        cin >> name;

        if (CreateDaemon(name) == 1) {
            cout << "Не создаётся демон";
        }
        delete[]name;
    } else if (selection == 3) {
        pid_t pid, signum;
        cout << "Введите pid: ";
        cin >> pid;
        cout << "Введите сигнал для отправки: ";
        cin >> signum;
        if (SendSignal(pid, signum) == 1) {
            cout << "Ошибка отправки сигнала" << endl;
        }
    } else if (selection == 5) {

    }
//    SendSignal(server_pid, SIGKILL);
    return 0;
}