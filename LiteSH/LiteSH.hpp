#ifndef LITESH_LITESH_HPP
#define LITESH_LITESH_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <arpa/inet.h>
#include <csignal>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

using namespace std;

int CreateProcess(char *nameProc);
int CreateDaemon(char *ProcName);

void sigHandler(int signum);
int SendSignal(pid_t pid, int signum);
int RecvSignal(int signum);

int NetWorkClient(char *command);

#endif //LITESH_LITESH_HPP
