#include <error.h>
#include "LiteSH.hpp"

int CreateProcess(char *ProcName) {
    int rv;
    char *arg[] = {ProcName, 0};
    switch (fork()) {
        case -1:
            perror("fork");
            return -1;
        case 0:
            // Child
            cout << "pid = " << getpid() << ", " << "ppid = " << getppid() << endl;
            execv(arg[0], arg);
        default:
            // Parent
            wait(&rv);
    }
    return 0;
}

int CreateDaemon(char *ProcName) {
    int rv;
    char *arg[] = {ProcName, 0};

    switch (fork()) {
        case -1:
            perror("fork");
            return 1;
        case 0:
            // создаём новый сеанс, чтобы не зависеть от родителя
            setsid();
            cout << "pid = " << getpid() << ", " << "ppid = " << getppid() << endl;
            //Переход в корень диска
            chdir("/");
            fclose(stdin);
            fclose(stdout);
            fclose(stderr);
            execv(arg[0], arg);
        default:
            wait(&rv);
    }
    return 0;
}

void sigHandler(int signo) {
    cout << "\tЗахват произошёл успешно" << endl;
}


int SendSignal(pid_t pid, int signum) {
    if (kill(pid, signum) == -1) {
        return 1;
    }
    return 0;
}

int RecvSignal(int signum) {
    if (signal(signum, sigHandler) == SIG_ERR) {
        return 1;
    }
    return 0;
}
//void NetWorkServer() {
//    struct sockaddr_in server, client;
//    int sock = socket(AF_INET, SOCK_STREAM, 0); // создание сокета
//    int enable = 1;
//    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
//        perror("setsockopt(SO_REUSEADDR) failed");
//// структура для сервера
//    server.sin_family = AF_INET;
//    server.sin_addr.s_addr = INADDR_ANY; // 0.0.0.0
//    server.sin_port = htons(2019); // порт сервера
//
//    bind(sock, (struct sockaddr*)&server, sizeof(server)); // связка с сокетом
//    listen(sock,5); // размер очереди
//
//    while(1){
//        char buf[255] = "";
//        int newsock, size;
//        socklen_t clnlen;
//
//        newsock = accept(sock, (struct sockaddr*)&client, &clnlen); // появление нового клиента
//        printf("New client: %s\n",inet_ntoa(client.sin_addr));
//
//        while((size = recv(newsock, buf, sizeof(buf), 0)) != 0) { // пока получаем от клиента
//            if (strcmp(buf, "CreateProcess") == 0) {
//                strcpy(buf, "1");
//                send(newsock, buf, sizeof(buf), 0);
//            } else if (strcmp(buf, "CreateDaemon") == 0) {
//                strcpy(buf, "2");
//                send(newsock, buf, sizeof(buf), 0);
//            } else if (strcmp(buf, "SendSignal") == 0) {
//                strcpy(buf, "3");
//                send(newsock, buf, sizeof(buf), 0);
//            } else if (strcmp(buf, "about") == 0) {
//                strcpy(buf, "4");
//                send(newsock, buf, sizeof(buf), 0);
//            } else {
//                strcpy(buf, "unknown command");
//                send(newsock, buf, sizeof(buf), 0);
//            }
//        }
//        close(newsock);
//    }
//    close(sock);
//}

int NetWorkClient(char *command) {
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
    send(sock, command, sizeof(buf), 0);
    recv(sock, buf, sizeof(buf),0);
    cout << "Server send: " << buf << endl;

    close(sock);
    int selection = atoi(buf);
    return selection;
}

pid_t net_proc() {
    pid_t pid;

    switch (pid = fork()) {
        case -1:
            perror("net fork");
            return 1;
        case 0:
            NetWorkServer();
    }

    return pid;
}