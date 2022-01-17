#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
sem_t plate;
sem_t forks[5];
int philo_no[5];
char mode[5];
int eaten[5];

int lefty(int p){
    return (p+4)%5;
}

int righty(int p){
    return (p+1)%5;
}

void*philosopher_i(void*i){
    do{  
        int*j=i;
        int k = *j;

        if(sleep(1)<0){
            printf("error: wasn't able to use sleep function");
        }

        if(sem_wait(&plate)<0){
            printf("error: sem_wait did not work\n");
        }
        mode[k]='H';
        printf("philosopher number %d has started feeling hungry so he is going to pick up the forks when he can\n",k+1);
        if(mode[k]=='H'&&mode[lefty(k)]!='E'&&mode[righty(k)]!='E'){
            mode[k]='E';
            eaten[k]++;
            if(sleep(1)<0){
                printf("error: wasn't able to use sleep function");
            }
            printf("philosopher number %d has picked up the forks to his left(%d) and right(%d) and has begun eating from the plate with them.He has eaten %d times\n",k+1,k+1,righty(k)+1,eaten[k]);
            if(sem_post(&forks[k])<0){
                printf("error: sem_post did not work\n");
            }
        }
        if(sem_post(&plate)<0){
            printf("error: sem_post did not work\n");
        }
        if(sem_wait(&forks[k])<0){
            printf("error: sem_wait did not work\n");
        }

        if(sleep(1)<0){
            printf("error: wasn't able to call sleep function");
        }

        if(sem_wait(&plate)<0){
            printf("error: sem_wait did not work\n");
        }
        mode[k]='T';
        printf("philosopher number %d has finished eating from the plate and is putting down the forks on his left(%d) and right(%d)\n",k+1,k+1,righty(k)+1);
        int l=lefty(k);
        int r=righty(k);
        if(mode[l]=='H'&&mode[lefty(l)]!='E'&&mode[righty(l)]!='E'){
            mode[l]='E';
            eaten[l]++;
            if(sleep(1)<0){
                printf("error: wasn't able to use sleep function");
            }
            printf("philosopher number %d has picked up the forks to his left(%d) and right(%d) and has begun eating from the plate with them.He has eaten %d times\n",l+1,l+1,righty(l)+1,eaten[l]);
            if(sem_post(&forks[l])<0){
                printf("error: sem_post did not work\n");
            }
        }
        if(mode[r]=='H'&&mode[lefty(r)]!='E'&&mode[righty(r)]!='E'){
            mode[r]='E';
            eaten[r]++;
            if(sleep(1)<0){
                printf("error: wasn't able to use sleep function");
            }
            printf("philosopher number %d has picked up the forks to his left(%d) and right(%d) and has begun eating from the plate with them.He has eaten %d times\n",r+1,r+1,righty(r)+1,eaten[r]);
            if(sem_post(&forks[r])<0){
                printf("error: sem_post did not work\n");
            }
        }
        if(sem_post(&plate)<0){
            printf("error: sem_post did not work\n");
        }
    }while(1);
}

int main(){
    pthread_t p[5];
    printf("there are five philosophers sitting in a circle with numbers 1, 2, 3, 4, 5\n");
    printf("each philosopher has two forks to his left and right\n");
    for(int i=0;i<5;i++){
        philo_no[i]=i;
        mode[i]='H';
        eaten[i]=0;
    }
    if(sem_init(&plate,0,5)<0){
        printf("error: wasn't able to initialise the main semaphore\n");
    }
    for(int i=0;i<5;i++){
        if(sem_init(&forks[i],0,0)<0){
            printf("error: wasn't able to initialise semaphore number %d\n",i+1);
        }
    }
    for(int i=0;i<5;i++){
        if(pthread_create(&p[i],NULL,philosopher_i,&philo_no[i])<0){
            printf("error: wasn't able to create separate thread for philosopher number %d\n",i+1);
        }
    }
    for(int i=0;i<5;i++){
        if(pthread_join(p[i],NULL)<0){
            printf("error: wasn't able to join the thread for philosopher number %d back into the main thread\n",i+1);
        }
    }
    return 0;
}