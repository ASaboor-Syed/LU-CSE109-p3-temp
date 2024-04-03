#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <dirent.h>      /* for opendir, readdir, closedir */

void *Malloc(size_t size);
int Stat(const char *restrict path, struct stat *restrict buf);
DIR* Opendir(const char *dirname);
struct dirent *Readdir(DIR *dirp);
int Closedir(DIR *dirp);

/* carried over from previous assignment */
ssize_t Read(int fd, void *buf, size_t nbyte);
ssize_t Write(int fd, const void *buf, size_t nbyte);
FILE *Fopen(const char *path, const char *mode);
int Fclose(FILE *fp);  /* ok to have this not return anything */
int Fseek(FILE *fp, long offset, int whence);
long Ftell(FILE *fp);
size_t Fread(void *ptr, size_t item_size, size_t num_items, FILE *fp);
size_t Fwrite(const void *ptr, size_t item_size, size_t num_items, FILE *fp); 
int System(const char *command);

#endif
