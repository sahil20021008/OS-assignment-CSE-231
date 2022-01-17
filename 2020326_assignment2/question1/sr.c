#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include <sys/time.h>

void s1_sig_handler(int signum, siginfo_t *info,void *extra){
    printf("sr:%d \n",info->si_value.sival_int);
}

void srf(int signum){
    int ret;
    asm volatile ("rdrand %0\n\t"
    :"=a"(ret)::);
    struct sigaction action;
    action.sa_sigaction=s1_sig_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags=SA_SIGINFO;
    if(sigaction(SIGTERM,&action,NULL)==-1){
        printf("error:couldn't register sigterm signal");
        return;
    }
    pid_t s=getpid();
    union sigval sign;
    sign.sival_int=ret;
    if(sigqueue(s,SIGTERM,sign)==-1){
        printf("error:wasn't able to send signal");
        return;
    }
}

int main(){
    struct itimerval it;
    it.it_value.tv_sec = 0;
    it.it_value.tv_usec = 500000;
    it.it_interval.tv_sec = 0;
    it.it_interval.tv_usec = 500000;
    signal(SIGALRM,srf);
    int te=setitimer(ITIMER_REAL,&it,NULL);
    if(te==-1){
        printf("error:wasn't able to set timer in sr");
        return -1;
    }
    while(1){

    }
    return 0;
}