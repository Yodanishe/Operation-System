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


int SendSignal(int pid, int signum) {
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

int NetWorkClient(char *command) {
    //структура для сокета
    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_port = htons(2018);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    int sock = socket(AF_INET,SOCK_STREAM,0);// создаём сокет

    if (connect(sock, (struct  sockaddr*)&server, sizeof(server)) < 0) { // соединяемся с сервером
        cout << "Connection failed" << endl;
        return -1;
    }

    char buf[255];
    memset(buf,0,256);
    //отправка сообщения
    send(sock, command, sizeof(buf), 0);
    recv(sock, buf, sizeof(buf),0);
    cout << "Server send: " << buf << endl;

    close(sock);
    int selection = atoi(buf);
    return selection;
}

