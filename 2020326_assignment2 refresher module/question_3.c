#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void *add(int a,int b){
    printf("%d",a+b);
    return NULL;
}
void *sub(int a,int b){
    printf("%d",a-b);
    return NULL;
}
void *mul(int a,int b){
    printf("%d",a*b);
    return NULL;
}
void *divd(int a,int b){
    if(b==0){
        printf("error denominator is 0");
        return NULL;
    }
    printf("%d",a/b);
    return NULL;
}
void *expo(int a,int b){
    printf("%d", (int)pow(a,b));
    return NULL;
}
int main(){//creating the array of pointers
    void (*ptr[])(int,int)={(void (*)(int, int)) add, (void (*)(int, int)) sub, (void (*)(int, int)) mul,
                            (void (*)(int, int)) divd, (void (*)(int, int)) expo};
    int choice;
    int alpha,beta;
    char c[10];
    printf("\nenter 0 for addition,\n1 for subtraction,\n2 for multiplication,\n3 for division,\n4 for exponent\n:");
    scanf("%s",c);
    choice= strtol(c,(char **)NULL,10);
    printf("\nenter first number:");
    char first[10];
    char second[10];
    scanf("%s",first);
    printf("\nenter second number:");
    scanf("%s",second);
    alpha= strtol(first,(char **)NULL,10);//first number for operation
    beta= strtol(second,(char **)NULL,10);//second number for operation
    printf("\nthe result is :");
    ptr[choice](alpha,beta);//executing function
    return 0;
}