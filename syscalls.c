#include <stdio.h>       /* for fprintf, fread, fwrite, fseek, ftell, fclose */
#include <stdlib.h>      /* for exit, system */
#include <unistd.h>      /* for read, write */
#include <errno.h>       /* for errno */
#include <string.h>      /* for strerror */
#include <sys/stat.h>    /* for stat */
#include <dirent.h>      /* for opendir, readdir, closedir */
#include <sys/types.h>   /* for dirent struct */

void *Malloc(size_t size){
    void *result = malloc(size);
    if (result == NULL){
        fprintf(stderr,"Malloc Failed\n");
        fprintf(stderr,"%d - %s",errno,strerror(errno));
        exit(errno);
    }
    return result;
}

// stat wrapped
int Stat(const char *restrict path, struct stat *restrict buf){
    int completed = 0;
    if((completed = stat(path,buf))==-1){ //err when stat outputs -1
        fprintf(stderr,"%d - %s\n",errno,strerror(errno));
        exit(errno);
    }
    return completed;
}

DIR* Opendir(const char *dirname){
    DIR* opened = NULL;
    if((opened = opendir(dirname))==NULL){ //err when dir doesnt exist
        fprintf(stderr,"%d - %s\n",errno,strerror(errno));
        exit(errno);
    }
    return opened;
}

struct dirent* Readdir(DIR *dirp){
    struct dirent* opened = NULL;
    if((opened = readdir(dirp))==NULL){ //err when dir doesnt exist
        fprintf(stderr,"%d - %s\n",errno,strerror(errno));
        exit(errno);
    }
    return opened;
}
int Closedir(DIR *dirp){
    int completed = 0;
    if((completed = closedir(dirp))==-1){ //err when stat outputs -1
        fprintf(stderr,"%d - %s\n",errno,strerror(errno));
        exit(errno);
    }
    return completed;
}

// carried over from previous assignment

// read wrapping
ssize_t Read(int fd, void *buf, size_t nbyte){
    ssize_t bytes_read = 0;
    if((bytes_read = read(fd,buf,nbyte))==-1){ //err when -1 things are read
        fprintf(stderr,"%d - %s\n",errno,strerror(errno));
        exit(errno);
    }
    return bytes_read;
}
// write wrapping
ssize_t Write(int fd, const void *buf, size_t nbyte){
    ssize_t bytes_wrote = 0;
    if((bytes_wrote = write(fd,buf,nbyte))==-1){ //err when -1 things are written
        fprintf(stderr,"%d - %s\n",errno,strerror(errno));
        exit(errno);
    }
    return bytes_wrote;
}

// fopen wrapping
FILE *Fopen(const char *path, const char *mode){
    FILE* opened = NULL;
    if((opened = fopen(path,mode))==NULL){ //err when file doesnt exist
        fprintf(stderr,"%d - %s\n",errno,strerror(errno));
        exit(errno);
    }
    return opened;
}

// fclose wrapping
int Fclose(FILE *fp){  /* ok to have this not return anything */
    int closed = fclose(fp); //kinda cant fail i guess
    return closed;
}

// fseek wrapping
int Fseek(FILE *fp, long offset, int whence){
    int seeked = 0;
    if((seeked = fseek(fp, offset, whence))==-1){ //err when fseeks outputs -1
        fprintf(stderr,"%d - %s\n",errno,strerror(errno));
        exit(errno);
    }
    return seeked;
}

// ftell wrapping
long Ftell(FILE *fp){
    long position = 0;
    if((position = ftell(fp))==-1){ //err when position is -1
        fprintf(stderr,"%d - %s\n",errno,strerror(errno));
        exit(errno);
    }
    return position;
}

// fread wrapping
size_t Fread(void *ptr, size_t item_size, size_t num_items, FILE *fp){
    size_t elem_read = 0;
    if((elem_read = fread(ptr,item_size,num_items,fp))<num_items){//err when number read is less than total elements
        fprintf(stderr,"%d - %s\n",errno,strerror(errno));
        exit(errno);
    }
    return elem_read;
}

// fwrite wrapping
size_t Fwrite(const void *ptr, size_t item_size, size_t num_items, FILE *fp){
    size_t elem_wrote = 0;
    if((elem_wrote = fwrite(ptr,item_size,num_items,fp))<num_items){//err when number of elements written is less than total numbers
        fprintf(stderr,"%d - %s\n",errno,strerror(errno));
        exit(errno);
    }
    return elem_wrote;
} 

// system wrapping
int System(const char *command){
    int status = 0;
    if (command == NULL && (status = system(command))==0){//err when no available shell
        fprintf(stderr,"%d - %s\n",errno,strerror(errno));
        exit(errno);
    }
    else if((status = system(command))==-1){//err when status is -1
        fprintf(stderr,"%d - %s\n",errno,strerror(errno));
        exit(errno);
    }
    return status;
}