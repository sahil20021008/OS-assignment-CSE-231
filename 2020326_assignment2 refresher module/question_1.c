//assignment 2 question 1
#include <stdlib.h>
#include <stdio.h>
int main(){
    int n;
    printf("enter no of rows in matrix:");
    char rows[10];
    scanf("%s",rows);
    n= strtol(rows,(char **)NULL,10);
    int matrix[n][1000];//creating matrix with n rows and a maximum of 1000 columns in each row
    for (int i = 0; i < n; ++i) {//setting number of columns in each row
        printf("please enter the number of columns in %dth row: ",i+1);
        char col[10];
        scanf("%s",col);
        printf("\n");
        int j= strtol(col,(char **)NULL,10);
        matrix[i][j] = -1;
    }
    for (int i = 0; i < n; ++i) {//putting number in each element of matrix
        for (int j = 0; j <1000; ++j) {
            if(matrix[i][j] == -1){
                break;
            }
            matrix[i][j]=1;
        }
    }
    printf("the final matrix is:\n");
    for (int i = 0; i < n; ++i) {//printing the matrix
        for (int j = 0; j < 1000; ++j) {
            if(matrix[i][j]==-1){
                break;
            }
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}