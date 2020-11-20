#ifndef MANAGING_THE_FILE_SYSTEM_COMMANDS_HPP
#define MANAGING_THE_FILE_SYSTEM_COMMANDS_HPP

#include <cstdio>
#include <iostream>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

int MV(char *oldpath, char *newpath);

int CP(char *oldpath, char *newpath);

int RM(char *filename);

long SizeFile(char *filename);

long SizeDir(char *filename);

int ls(char *dirname);

void mapping_process();


#endif //MANAGING_THE_FILE_SYSTEM_COMMANDS_HPP
