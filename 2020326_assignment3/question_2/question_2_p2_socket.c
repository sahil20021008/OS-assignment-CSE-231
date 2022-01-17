#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <unistd.h>
#define PORT 3490

int main(){
    int sockfd, sock2;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == 0) {
        printf("error wasn't able to register socket");
        return -1;
    }
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt))) {
        printf("error: setsockopt didn't work");
        return -1;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address))<0) {
        printf("error: bind did not work");
        return -1;
    }
    if (listen(sockfd, 10) < 0) {
        printf("error: listen did not work");
        return -1;
    }
    if ((sock2 = accept(sockfd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        printf("error: wasn't able to accept connection");
        return -1;
    }
    for(int i=0;i<10;i++){
        char buffer[5][7];
        if(read(sock2,buffer,sizeof(buffer))<0){
            printf("error: wasn't able to recieve the string");
            continue;
        }
        for(int j=0;j<5;j++){
            printf("%d : %c%c%c%c%c \n",buffer[j][5],buffer[j][0],buffer[j][1],buffer[j][2],buffer[j][3],buffer[j][4]);
        }
        char tem[3];
        sprintf(tem,"%d",(int)buffer[4][5]);
        if(write(sock2,tem,strlen(tem)+1)<0){
            printf("error: wasn't able to send highest index");
            continue;
        }
    }
    close(sockfd);
    close(sock2);
    return 0;
}