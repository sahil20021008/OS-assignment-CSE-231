//assignment 1 question 5
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
void swapper(char **a,char **b){//for swapping elements of array
    char *temp=*a;
    *a=*b;
    *b=temp;
}
bool compare(char *a,char *b){//for comparing the numbers of array
    unsigned long long n= strlen(a);
    unsigned long long m= strlen(b);
    if(n>m){//if length of numbers are different
        return true;
    }else if(m>n){
        return false;
    }else{//if length of numbers is same, compare the digits using strcmp()
        int p= strcmp((const char *) a, (const char *) b);
        return (p>=0);
    }
}
void bubble_sort( unsigned long long n,char c[n][100] ){//sort array using bubble sort
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) {
            if(compare( c[j],c[j+1])){//compare elements
                swapper((char **) c[j], (char **) c[j + 1]);//swap elements
            }
        }
    }
}
int comp(const char *a,const char *b){//for comparing two elements of array, returning integer
    int n= (int)strlen(a);
    int m= (int)strlen(b);
    if(n!=m){
        return n-m;
    }else{
        return strcmp(a,b);
    }
}
int bin_search(unsigned long long n,char c[n][100],char *x){//binary search
    int low=0;
    int high=(int)n-1;
    int mid;
    while(low <= high){
        mid = (low+(high-low)/2);//index of middle element
        int s= comp(x,c[mid]);
        if(s==0){//if elements are same
            return mid;
        }else if(s>0){//if x is greater than middle element
            low=mid+1;
        }else{//if x is smaller than middle element
            high=mid-1;
        }
    }
    return -1;
}
int main(){//we are assuming user will input the required numbers
    unsigned long long n;
    printf("input length of array\n");
    char length[10];
    scanf("%s",length);
    n= strtol(length,(char **)NULL,10);
    char array[n][100];
    printf("input %lld elements of array\n",n);
    for (int i = 0; i < n; ++i) {
        scanf("%s",array[i]);
    }
    printf("input the element you want to find\n");
    char finder[50];
    scanf("%s",finder);
    bubble_sort(n,array);//sort the array
    printf("the sorted array is: ");
    for (int i = 0; i < n; ++i) {
        printf("%s ",array[i]);
    }
    printf("\n");
    int ans=bin_search(n,array,finder);//perform binary search on array
    if(ans== -1){
        printf("the number is not in the array");//if element is not in array
    }else{
        printf("the element of the array is at index: %d",ans);/*print which index of array element is at*/
    }
    return 0;
}

