//assignment 1 question 3
#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("enter 0 if you want to swap numbers otherwise enter 1 if you want to swap arrays\n");
    int n;
    char str[10];
    scanf("%s",str);//taking choice input
    n = strtol(str,(char **)NULL,10);
    if(n==0){
        int a,b;
        char alpha[10],beta[10];//taking input of both numbers
        printf("enter first number\n");
        scanf("%s",alpha);
        printf("enter second number\n");
        scanf("%s",beta);
        a= strtol(alpha,(char **)NULL,10);
        b= strtol(beta,(char **)NULL,10);
        printf("the initial numbers are: %d, %d \n",a,b);
        int c;
        c=a;
        a=b;//swapping numbers
        b=c;
        printf("the swapped numbers are: %d, %d",a,b);
    }else{
        printf("enter no of elements in array\n");//no of elements in array
        int length;
        char lengthy[10];
        scanf("%s",lengthy);
        length= strtol(lengthy,(char **)NULL,10);
        int a[length];
        int b[length];
        printf("enter elements of first array\n");
        for (int i = 0; i < length; ++i) {//input of first array
            char index[10];
            scanf("%s",index);
            a[i]= strtol(index,(char **)NULL,10);
        }
        printf("enter elements of second array\n");
        for (int i = 0; i < length; ++i) {//input of second array
            char index[10];
            scanf("%s",index);
            b[i]= strtol(index,(char **)NULL,10);
        }
        printf("initial arrays are:\n");//printing initial arrays
        for (int i = 0; i < length; ++i) {
            printf("%d ",a[i]);
        }
        printf("\n");
        for (int i = 0; i < length; ++i) {
            printf("%d ", b[i]);
        }
        printf("\n");
        int c;
        for (int i = 0; i < length; ++i) {//swapping arrays
            c=a[i];
            a[i]=b[i];//swapping arrays
            b[i]=c;
        }
        printf("swapped arrays are:\n");//printing swapped arrays
        for (int i = 0; i < length; ++i) {
            printf("%d ",a[i]);
        }
        printf("\n");
        for (int i = 0; i < length; ++i) {
            printf("%d ", b[i]);
        }
    }
    return 0;//end of function
}
