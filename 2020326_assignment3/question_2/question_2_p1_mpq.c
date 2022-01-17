#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
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

struct mesg_buffer {
    long mesg_type;
    char mesg_text[5][7];
} message,recev;

int main(){
    char rante[50][7];
    ranter(rante);
    key_t fto=ftok("mpq",12);
    key_t fto2=ftok("mpq2",15);
    int i=0;
    while(i<50){
        int msgid = msgget(fto, 0666 | IPC_CREAT);
        int msgid2 = msgget(fto2, 0666 | IPC_CREAT);
        strcpy(message.mesg_text[0],rante[i++]);
        strcpy(message.mesg_text[1],rante[i++]);
        strcpy(message.mesg_text[2],rante[i++]);
        strcpy(message.mesg_text[3],rante[i++]);
        strcpy(message.mesg_text[4],rante[i++]);
        message.mesg_type=1;
        if(msgsnd(msgid,&message,sizeof(message),0)<0) {
            printf("error: weren't able to send message");
            i-=5;
            continue;
        }
        if(msgrcv(msgid2,&recev,sizeof(recev),1,0)<0) {
            printf("Error: wasnt able to receive highest index");
            continue;
        }
        printf("the highest index was %s\n",recev.mesg_text[0]);
        msgctl(msgid,IPC_RMID,NULL);
        msgctl(msgid2,IPC_RMID,NULL);
    }
    return 0;
}