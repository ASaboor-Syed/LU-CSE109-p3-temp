#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>    /* for stat */
#include "syscalls.h"
#include <string.h>


int countIncludes(char* path){
    int count = 0;
    FILE* file = Fopen(path,"r");
    char *line = NULL;
    size_t len = 0;
    while ((getline(&line, &len, file)) != -1) {
        char* temp = strstr(line, "#include");
        if(temp!=NULL){
            count+=1;
        }
    }

    free(line);
    Fclose(file);
    return count;
}

int traverseDir(char* path){
    
}

int parseArgs(int argc, char** argv, char* path){
    if (argc!=2){
        fprintf(stderr,"incorrect number of arguments\n");
        exit(97);
    }
    struct stat buffer;
    char* inPath = argv[1];
    Stat(inPath,&buffer);
    if (S_ISDIR(buffer.st_mode)){ //is dir
        fprintf(stdout, "Directory\n");
    }
    else{ //is file
        char *symlinkpath = inPath;
        char actualpath [PATH_MAX+1];
        realpath(symlinkpath, actualpath);

        path = actualpath;
        fprintf(stdout,"%s - %d\n",path,countIncludes(path));
    }
    return 0;
}