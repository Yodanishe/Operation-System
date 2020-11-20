#include <iostream>
#include <fstream>

using namespace std;

extern "C" {
void informate() {
    cout << "Авторы: Дак Михаил, Лозовой Владислав, Степанов Владислав" << endl
         << "Программа предназначена для создания процессов, демонов, " << endl
         << "отправки сигналов процессам и получения сигналов" << endl;
    ifstream signals("/home/misha/Labs/Operation-System/LiteSH/bin/signals.txt");
    string SigName;
    cout << "Доступные номера сигналов" << endl;
    for (int i = 1; getline(signals, SigName); i++) {
        cout << "\E[36m" << i << " - ";
        cout << "\E[39m";
        cout << SigName << endl;
    }
    signals.close();
}


void commands() {
    cout << "Введите 'CreateProcess' для создания процесса" << endl;
    cout << "Введите 'CreateDaemon' для создания демонов" << endl;
    cout << "Введите 'SendSignal' для отправки сигнала процессу" << endl;
    cout << "Введите 'about' для получения информации о проекте" << endl;
    cout << "Введите 'exit' для закрытия программы" << endl << endl;
}

}

int main() {
    return 0;
}