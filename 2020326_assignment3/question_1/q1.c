#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main(){
    pid_t p1,p2,p3,parent;
    p1=fork();
    if(p1<0){
        printf("error: p1 wasn't forked");
    }else if(p1==0){
        char*pt1[]={"./p1",NULL};
        execv("./p1",pt1);
    }else{
        p2=fork();
        if(p2<0){
            printf("error: wasn't able to fork p2");
        }else if(p2==0){
            char*pt2[]={"./p2",NULL};
            execv("./p2",pt2);
        }else{
            p3=fork();
            if(p3<0){
                printf("error: wasn't able to fork p3");
            }else if(p3==0){
                char*pt3[]={"./p3",NULL};
                execv("./p3",pt3);
            }else{
                syscall(449,5);
                struct tm* local;
                time_t t = time(NULL);
                local = localtime(&t);
                printf("q1 start time and date: %s\n",asctime(local));
                for(int i=0;i<10;i++){
                    printf("we are in process q1\n");
                }
                t = time(NULL);
                local = localtime(&t);
                printf("q1 end time and date: %s\n",asctime(local));
            }
        }
    }
    return 0;
}