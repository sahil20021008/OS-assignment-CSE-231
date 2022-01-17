#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){
    struct tm* local;
    time_t t = time(NULL);
    local = localtime(&t);
    printf("p3 start time and date: %s\n",asctime(local));
    for(int i=0;i<30;i++){
        printf("we are in process p3\n");
    }
    t = time(NULL);
    local = localtime(&t);
    printf("p3 end time and date: %s\n",asctime(local));
    return 0;
}