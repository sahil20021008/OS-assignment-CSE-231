#include <stdio.h>
#include <stdlib.h>

extern void _b(long long int a);
void a(){
    printf("we are in function a\n");
    long long int at;
    printf("enter 64 bit number:\n");
    scanf("%lld",&at);
    _b(at);
}

int main(){
    printf("we are in main function\n");
    a();
    return 0;
}