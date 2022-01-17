#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int rfd=open("/dev/urandom",O_RDONLY);
    if(rfd<0){
        printf("error: wasn't able to open the file.\nPlease run the program again");
    }else{
        char rand[8];
        ssize_t check=read(rfd,rand,sizeof(rand));
        if(check<0){
            printf("error: wasn't able to read data from urandom file\n");
        }else{
            long output=syscall(449,rand);
            if(output==-1){
                printf("error: wasn't able to make queue");
            }
            printf("the initial random 8 bytes are: %s\n",rand);
        }
    }
    return 0;
}

