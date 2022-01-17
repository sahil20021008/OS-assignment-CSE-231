#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int fd;
    char*fifo="pipe";
    mkfifo(fifo,0666);
    for(int i=0;i<10;i++){
        fd=open(fifo,O_RDONLY);
        char buffer[5][7];
        if(read(fd,buffer,sizeof(buffer))<0){
            printf("error: wasn't able to recieve the string");
            continue;
        }
        for(int j=0;j<5;j++){
            printf("%d : %c%c%c%c%c \n",buffer[j][5],buffer[j][0],buffer[j][1],buffer[j][2],buffer[j][3],buffer[j][4]);
        }
        close(fd);
        fd=open(fifo,O_WRONLY);
        char tem[3];
        sprintf(tem,"%d",(int)buffer[4][5]);
        if(write(fd,tem,strlen(tem)+1)<0){
            printf("error: wasn't able to send highest index");
        }
        close(fd);
    }
    return 0;
}