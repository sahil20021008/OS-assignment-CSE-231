//assignment 3 question 4
#include <stdio.h>
#include <stdlib.h>
void bubble(int n,int arr[]){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) {
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void selection(int n,int arr[]){
    for (int i = 0; i < n-1; ++i) {
        int mint=i;
        for (int j = i+1; j < n; ++j) {
            if(arr[j]<arr[mint]){
                mint=j;
            }
        }
        if(mint!=i){
            int temp=arr[mint];
            arr[mint]=arr[i];
            arr[i]=temp;
        }
    }
}
int main(){
    printf("enter no of elements in array\n");
    int n;
    char length[20];
    scanf("%s",length);
    n= strtol(length,(char**)NULL,10);
    int arr[n];
    printf("enter %d elements of array:\n",n);
    for (int i = 0; i < n; ++i) {
        char arrt[20];
        scanf("%s",arrt);
        arr[i]= strtol(arrt,(char **)NULL,10);
    }
    printf("please enter 0 for bubble sort or 1 for selection sort");
    char choice[5];
    scanf("%s",choice);
    int c= strtol(choice,(char **)NULL,10);
    if(c==0){
        bubble(n,arr);
    }else if(c==1){
        selection(n,arr);
    }else{
        printf("incorrect choice");
        return 1;
    }
    printf("the sorted array is:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ",arr[i]);
    }
    return 0;
}