#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/wait.h>

void s1_sig_handler(int signum, siginfo_t *info,void *extra){
    printf("%d \n",info->si_value.sival_int);
}
void s1(){
    char*sr[]={"./sr",NULL};
    char*st[]={"./st",NULL};
    pid_t child=fork();
    if(child==0){
        struct sigaction action;
        action.sa_sigaction=s1_sig_handler;
        sigemptyset(&action.sa_mask);
        action.sa_flags=SA_SIGINFO;
        if(sigaction(SIGTERM,&action,NULL)==-1){
            printf("error:couldn't register sigterm signal");
            return;
        }
    }else if(child<0){
        printf("error wasn't able to fork to s1");
        return;
    }else{
        pid_t sr_f,st_f;
        sr_f=fork();
        if(sr_f==0){
            execv("./sr",sr);
        }else if(sr_f<0){
            printf("error: wasn't able to fork to sr");
            return;
        }else{
            st_f=fork();
            if(st_f==0){
                execv("./st",st);
            }else if(st_f<0){
                printf("error: wasn't able to fork to st");
                return;
            }else{

            }
        }
    }
}
int main(){
    s1();
    return 0;
}