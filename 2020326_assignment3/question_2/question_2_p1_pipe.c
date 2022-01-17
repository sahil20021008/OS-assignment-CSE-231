#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

void ranter(char rante[50][7]){
    for(int i=0;i<50;i++){
        for(int j=0;j<6;j++){
            rante[i][j]=rand()%26+65;
        }
        rante[i][5]=i;
        rante[i][6]='\0';
    }
}

int main(){
    char rante[50][7];
    ranter(rante);
    int fd;
    char*fifo="pipe";
    mkfifo(fifo,0666);
    int i=0;
    while(i<50){
        char sende[5][7];
        strcpy(sende[0],rante[i++]);
        strcpy(sende[1],rante[i++]);
        strcpy(sende[2],rante[i++]);
        strcpy(sende[3],rante[i++]);
        strcpy(sende[4],rante[i++]);
        fd=open(fifo,O_WRONLY);
        if(write(fd,&sende,5*7*sizeof(char))<0){
            i-=5;
            printf("error: wasn't able to send strings");
            continue;
        }
        close(fd);
        fd=open(fifo,O_RDONLY);
        char buffer[3];
        if(read(fd,buffer,3)<0){
            printf("error:wasn't able to receive highest index\n");
            continue;
        }
        printf("the highest index was %s\n",buffer);
        close(fd);
    }
    return 0;
}