#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 3490

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
    int sock=0;
    struct sockaddr_in serv_addr;
    if ((sock = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        printf("error: wasn't able to register socket");
        return -1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if(inet_pton(AF_INET, "192.168.10.128", &serv_addr.sin_addr)<=0) {
        printf("error: invalid address");
        return -1;
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("error: wasn't able to connect");
        return -1;
    }
    int i=0;
    while(i<50) {
        char sende[5][7];
        strcpy(sende[0],rante[i++]);
        strcpy( sende[1],rante[i++]);
        strcpy(sende[2],rante[i++]);
        strcpy(sende[3],rante[i++]);
        strcpy( sende[4],rante[i++]);
        if(write(sock,&sende,5*7*sizeof(char))<0){
            i=i-5;
            printf("error: message wasn't sent please try again");
            continue;
        }
        char buffer[3];
        if(read(sock,buffer,3)<0){
            printf("error:wasn't able to receive highest index\n");
            continue;
        }
        printf("the highest index was %s\n",buffer);
    }
    close(sock);
    return 0;
}