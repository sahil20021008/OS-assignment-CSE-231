//assignment 1 question 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char binary[256],binary2[256],n1[100],n2[100];//initialising arrays for two integers
void divide(char n[100]){//function for dividing integer
    char ans[100];
    ans[0]='\0';
    int index=0;
    int temp=n[index]-'0';
    while (temp<2){
        temp=temp*10+(int)(n[++index]-'0');
    }
    while (strlen(n)>index){
        char temper[1];
        temper[0]=(char)((temp / 2) + 48);
        strcat(ans, temper);
        temp=(temp%2)*10+(n[++index]-'0');
    }
    if(strlen(ans)==0){
        strcat(ans,"0");
    }
    n[0]='\0';
    strcat(n,ans);
}
void bint(char n[100],char bin[256]){//conversion from integer to binary
    while (strcmp(n,"0")!=0){
        unsigned long long c= strlen(n);
        if((int)(n[c-1]-'0')%2==0){
            strrev(bin);
            strcat(bin,"0");
            strrev(bin);
        } else{
            strrev(bin);
            strcat(bin,"1");
            strrev(bin);
        }
        divide(n);
    }
    char zero[256];
    unsigned long long del= strlen(bin);
    for (int i = 0; i < 256 - del; ++i) {
        strcat(zero,"0");
    }
    strcat(zero,bin);
    bin[0]='\0';
    strcat(bin,zero);
}
int main(){
    char num1[32],num2[32];
    printf("enter 1st number:");
    scanf("%s",n1);
    printf("\nenter 2nd number:");
    scanf("%s",n2);
    binary[0]='\0';
    binary2[0]='\0';
    bint(n1,binary);
    bint(n2,binary2);
    int i=0;
    int j=0;
    while(i<256){
        char temp[8]={binary[i++], binary[i++], binary[i++], binary[i++], binary[i++], binary[i++], binary[i++], binary[i++]};
        num1[(int)(i-1)/8]= (char)(strtol(temp,(char**)NULL,2));
    }
    while(j<256){
        char temp[]={binary2[j++],binary2[j++],binary2[j++],binary2[j++],binary2[j++],binary2[j++],binary2[j++],binary2[j++]};
        num2[(int)(j-1)/8]= (char)(strtol(temp,(char**)NULL,2));
    }
    char ans[32];
    for (int k = 32; k >0; ++k) {
        ans[k]=(char)(num1[k]+num2[k]);
    }
    printf("the answer is:");
    for (int k = 0; k < 32; ++k) {
        char temper[1];
        temper[0]=ans[k];
        printf("%ld", strtol(temper,(char **)NULL,10));
    }
    return 0;
}
