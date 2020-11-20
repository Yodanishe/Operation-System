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

    struct sockaddr_in server, client;
    int sock = socket(AF_INET, SOCK_STREAM, 0); // создание сокета
    int enable = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
        perror("setsockopt(SO_REUSEADDR) failed");
// структура для сервера
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY; // 0.0.0.0
    server.sin_port = htons(2019); // порт сервера

    bind(sock, (struct sockaddr *) &server, sizeof(server)); // связка с сокетом
    listen(sock, 5); // размер очереди


    while(1){
        char buf[255][255];
        int newsock, size;
        socklen_t clnlen;

        newsock = accept(sock, (struct sockaddr*)&client, &clnlen); // появление нового клиента
        printf("New client: %s\n",inet_ntoa(client.sin_addr));

        while((size = recv(newsock, buf, sizeof(buf), 0)) != 0)
        {
            if (buf == NULL){ //Если флаги не введены
                //Ловим сигналы Нибиру
            } else if (!strcmp(buf[1], "CreateProcess")) { //Если процесс нужно запустить в фоновом режиме
                CreateProcess(buf[2]);
            } else if (!strcmp(buf[1],"CreateDaemon")){ //Если процесс нужно запустить НЕ в фоне
                CreateDaemon(buf[2]);
            } else if (!strcmp(buf[1],"CreateDaemon")) {
                int signum = atoi(buf[3]);
                int pid = atoi(buf[2]);
                SendSignal(pid, signum);
            }
            send(newsock, buf, sizeof(buf), 0); // отправляем эхо
        } // пока получаем от клиента

        close(newsock);
    }
    close(sock);

    return 0;
}