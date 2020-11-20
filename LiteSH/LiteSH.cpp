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
