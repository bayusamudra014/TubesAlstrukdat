#include "file.h"
#include <stdio.h>
#include "../wordmachine/wordmachine.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

void f_read_file(const char* path, char* buffer, int size){
    FILE *fp;
    fp = fopen(path,"r");

    buffer[size];
    int i = 0;
    wm_start_word(fp);
    while (!wm_end_word){
        buffer[i] = wm_current_word.contents;
        i += 1;
        wm_adv_word();
    }
    fclose(fp);
}

void f_write_file(const char* path, const char* buffer, int size){
    buffer[size];
    FILE *fp;
    fp = fopen(path,"w");
    fputs(buffer, fp);
    fclose(fp);
}

boolean f_exist(const char* path){
    FILE *fp;
    if (fp = NULL){
        return false;
    }
    else{
        return true;
    }
    fclose(fp);
}

boolean f_writeable(const char* path){
    return (!access(path, W_OK));
}

boolean f_readable(const char* path){
    return (!access(path, R_OK ));
}

boolean f_is_file(const char* path){
    struct stat s;
    if(stat(path,&s) == 0){
        if(s.st_mode & S_IFREG){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}