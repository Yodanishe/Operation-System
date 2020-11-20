#include <iostream>
#include <arpa/inet.h>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]) {
    //структура для сокета
    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_port = htons(2019);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    int sock = socket(AF_INET,SOCK_STREAM,0);// создаём сокет

    if (connect(sock, (struct  sockaddr*)&server, sizeof(server)) < 0) { // соединяемся с сервером
        cout << "Connection failed" << endl;
        return -1;
    }

    char buf[255] = "";
    //отправка сообщения
    send(sock, argv[1], sizeof(buf), 0);
    recv(sock, buf, sizeof(buf),0);
    cout << "Server send: " << buf << endl;

    close(sock);
}