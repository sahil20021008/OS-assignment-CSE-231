#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){
    struct tm* local;
    time_t t = time(NULL);
    local = localtime(&t);
    printf("p1 start time and date: %s\n",asctime(local));
    for(int i=0;i<50;i++){
        printf("we are in process p1\n");
    }
    t = time(NULL);
    local = localtime(&t);
    printf("p1 end time and date: %s\n",asctime(local));
    return 0;
}