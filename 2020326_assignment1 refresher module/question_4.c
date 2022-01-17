// assignment 1 question 4
#include <stdio.h>
int main() {
    char c[1000];
    char r[1000];
    printf("enter input string:\n");
    fgets(c,1000,stdin);//taking input string
    int i= 0;
    while(c[i]!='\0'){//finding length of input
        i++;
    }
    int j;
    for(j=0;j<i;j++){//swapping input
        r[j]=c[i-j-1];
    }
    r[j]='\0';
    printf("%s", r);//printing reversed string
    return 0;
}