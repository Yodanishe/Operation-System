#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

using namespace std;

int main() {
    bool work = 1;
    struct sockaddr_in server, client;
    int sock = socket(AF_INET, SOCK_STREAM, 0); // создание сокета
    int enable = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
        perror("setsockopt(SO_REUSEADDR) failed");
    // структура для сервера
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY; // 0.0.0.0
    server.sin_port = htons(2018); // порт сервера

    bind(sock, (struct sockaddr*)&server, sizeof(server)); // связка с сокетом
    listen(sock,5); // размер очереди

    while(work){
        char buf[255];
        memset(buf,0,256);
        int newsock, size;
        socklen_t clnlen;

        newsock = accept(sock, (struct sockaddr*)&client, &clnlen); // появление нового клиента
        printf("New client: %s\n",inet_ntoa(client.sin_addr));

        while((size = recv(newsock, buf, sizeof(buf), 0)) != 0) { // пока получаем от клиента
            if (strcmp(buf, "CreateProcess") == 0) {
                strcpy(buf, "1");
                send(newsock, buf, sizeof(buf), 0);
            } else if (strcmp(buf, "CreateDaemon") == 0) {
                strcpy(buf, "2");
                send(newsock, buf, sizeof(buf), 0);
            } else if (strcmp(buf, "SendSignal") == 0) {
                strcpy(buf, "3");
                send(newsock, buf, sizeof(buf), 0);
            } else if (strcmp(buf, "about") == 0) {
                strcpy(buf, "4");
                send(newsock, buf, sizeof(buf), 0);
            }else if (strcmp(buf, "exit") == 0) {
                strcpy(buf, "5");
                work = 0;
                send(newsock,buf,sizeof(buf),0);
            } else {
                strcpy(buf, "unknown command");
                send(newsock, buf, sizeof(buf), 0);
            }
        }
        close(newsock);
    }
    close(sock);
}