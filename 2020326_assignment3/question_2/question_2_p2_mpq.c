#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/wait.h>

struct mesg_buffer {
    long mesg_type;
    char mesg_text[5][7];
} message,recev;

int main(){
    key_t fto=ftok("mpq",12);
    key_t fto2=ftok("mpq2",15);
    for(int i=0;i<10;i++){
        int msgid=msgget(fto, 0666 | IPC_CREAT);
        int msgid2 = msgget(fto2, 0666 | IPC_CREAT);
        if(msgrcv(msgid,&message,sizeof(message),1,0)<0){
            printf("error: wasn't able to receive the string");
            i--;
            continue;
        }
        for(int j=0;j<5;j++){
            printf("%d : %c%c%c%c%c \n",message.mesg_text[j][5],message.mesg_text[j][0],message.mesg_text[j][1],message.mesg_text[j][2],message.mesg_text[j][3],message.mesg_text[j][4]);//buffer[j][5],buffer[j][0],buffer[j][1],buffer[j][2],buffer[j][3],buffer[j][4]);
        }
        sprintf(recev.mesg_text[0],"%d",(int)message.mesg_text[4][5]);
        recev.mesg_type=1;
        if(msgsnd(msgid2,&recev,sizeof(recev),0)<0){
            printf("error: wasn't able to send highest index");
            i--;
            continue;
        }
        msgctl(msgid,IPC_RMID,NULL);
        msgctl(msgid2,IPC_RMID,NULL);
    }
    return 0;
}