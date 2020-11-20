#include <cstring>
#include "commands.hpp"

using namespace std;

int MV(char *oldpath, char *newpath) {
    cout << "Перемещение файла из " << oldpath << " В " << newpath << endl;
    if (rename(oldpath, newpath) == -1) {
        cout << "Ошибка перемещения файла" << endl << endl;
        return 1;
    }

    return 0;
}

int CP(char *oldpath, char *newpath) {
    cout << "Копироване файла" << endl;

    FILE *old = fopen(oldpath, "r");
    if (!old) {
        cout << "Файл отсутствует" << endl;
        return 1;
    }
    FILE *update = fopen(newpath, "wr");
    if (!update) {
        cout << "Ошибка создания файла" << endl;
    }

    char temp;
    while ((temp = getc(old)) != EOF) {
        fputc(temp, update);
    }
    fclose(old);
    fclose(update);

    return 0;
}

int RM(char *filename) {
    cout << "Удаление файла" << filename << endl;
    if (remove(filename) == -1) {
        cout << "Ошибка удаления файла" << endl;
        return 1;
    }
    return 0;
}

long SizeFile(char *filename) {
    struct stat buf;
    FILE *fp;

    if ((fp = fopen(filename, "rb")) == NULL) {
        return -1;
    }
    stat(filename, &buf);

    cout << "Размер файла: " << buf.st_size << endl;

    return buf.st_size;;
}

long SizeDir(char *filename) {
    long DirSize = 0;
    struct dirent *pDir;
    DIR *dir;

    if ((dir = opendir(filename)) == NULL) {
        return -1;
    }

    while ((pDir = readdir(dir)) != NULL) {
        char buf[512];
        memset(buf, 0, sizeof(buf));
        strcat(buf, filename);
        strcat(buf, pDir->d_name);
        DirSize += SizeFile(buf); //Все файлы
    }
    if (DirSize < 0) {
        return -1;
    }
    closedir(dir);

    cout << "Размер директории: " << DirSize << endl;

    return 0;
}

int ls(char *dirname) {
    cout << "Отображение всех файлов" << endl;

    struct dirent *pDir;
    DIR *dir;

    if ((dir = opendir(dirname)) == NULL) {
        cout << "Файлов в директории не существует" << endl;
        return 1;
    }

    while ((pDir = readdir(dir)) != NULL) {
        cout << pDir->d_ino << endl;
    }

    closedir(dir);
    return 0;
}

void mapping_process() {
    struct dirent *pDir;
    DIR *dir;

    dir = opendir("/proc/");
    cout << "PID\t" << "Name" << endl;

    while ((pDir = readdir(dir)) != NULL) { //Проход по директории
        if (isdigit(pDir->d_name[0]) != 0) {
            char proc_path[100] = "/proc/";
            strcat(proc_path, pDir->d_name);
            strcat(proc_path, "/status");
            FILE *proc_info = fopen(proc_path, "r");

            char *proc_name = new char[100];
            char *temp = new char[100];

            fscanf(proc_info, "%s%s", temp, proc_name);
            cout << pDir->d_name << "\t" << proc_name << endl;

            delete proc_name;
            delete temp;
            fclose(proc_info);
        }
    }
    closedir(dir);
}