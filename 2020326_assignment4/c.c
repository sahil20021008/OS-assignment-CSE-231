#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    char rande[8];
    long output=syscall(450,rande);
    printf("the final 8 bytes are: %s\n",rande);
    return 0;
}