#include <iostream>
#include <cstring>
#include <dlfcn.h>
#include "LiteSH.hpp"

using namespace std;

int main(int argc, char **argv) {
    char *error;
    void *handle = dlopen("/home/misha/Labs/Operation-System/LiteSH/libs/libinfo.so", RTLD_LAZY);
    if (!handle) {
        fputs (dlerror(), stderr);
        exit (-1);
    }

    if ((error = dlerror()) != NULL) {
        fprintf (stderr, "%s\n", error);
        exit (-1);;
    }

//    if (RecvSignal(SIGINT) == 1) {
//        cout << "Ошибка получения сигнала" << endl;
//    }
//    sleep(60);

    typedef void (*func_commands)();
    typedef void (*func_info)();
    func_commands commands = (func_commands)dlsym(handle,"commands");
    func_info info = (func_info)dlsym(handle,"informate");
    if ((error = dlerror()) != NULL) {
        fprintf (stderr, "%s\n", error);
        exit(-1);
    }
    commands();

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
    } else if (selection == 4) {
        info();
    } else if (selection == 5) {

    }
//    SendSignal(server_pid, SIGKILL);
    dlclose(handle);
    return 0;
}