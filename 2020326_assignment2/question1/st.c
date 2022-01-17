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
    printf("st:%d \n",info->si_value.sival_int);
}
void stf(int signum){
    unsigned int one;
    unsigned int two;
    asm volatile("rdtsc" 
    : "=a" (one), "=d" (two) :);
    union sigval sign;
    sign.sival_int=one;
    struct sigaction action;
    action.sa_sigaction=s1_sig_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags=SA_SIGINFO;
    if(sigaction(SIGTERM,&action,NULL)==-1){
        printf("error:wasn't able to register SIGTERM signal");
        return;
    }
    pid_t s=getpid();
    if(sigqueue(s,SIGTERM,sign)==-1){
        printf("error:wasn't able to send signal");
    }
    sign.sival_int=two;
    if(sigqueue(s,SIGTERM,sign)==-1){
        printf("error:wasn't able to send signal");
    }
}
int main(){
    struct itimerval it_val;
    it_val.it_value.tv_sec = 0;
    it_val.it_value.tv_usec = 250000;
    it_val.it_interval.tv_sec = 0;
    it_val.it_interval.tv_usec = 500000;
    signal(SIGALRM, stf);
    int te=setitimer(ITIMER_REAL,&it_val,NULL);
    if(te==-1){
        printf("error: wasn't able to set timer");
        return -1;
    }
    while(1){

    }
    return 0;
}