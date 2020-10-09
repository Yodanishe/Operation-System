#ifndef MANAGING_THE_FILE_SYSTEM_COMMANDS_HPP
#define MANAGING_THE_FILE_SYSTEM_COMMANDS_HPP
#include <cstdio>
#include <iostream>

using namespace std;

int move(char *oldpath, char *newpath);
int copy(char *oldpath, char *newpath);
int deleting(char *filename);

#endif //MANAGING_THE_FILE_SYSTEM_COMMANDS_HPP
