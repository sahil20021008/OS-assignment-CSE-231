#include <stdio.h>
#include <stdint.h>
#include <sys/syscall.h>
#include <unistd.h>

int main(){
    float mat1[4][5];
    float mat2[4][5];
    for(int i = 0;i<4;i++){
        for(int j = 0;j<5;j++){
            mat1[i][j] = i+j;
        }
    }
    printf("Original matrix:\n");
    for(int i = 0;i<4;i++){
        for(int j = 0;j<5;j++){
            printf("%f ",mat1[i][j]);
        }
        printf("\n");
    }
    long output = syscall(448,mat1,mat2,4,5);
    printf("System call has returned %d \n",output);
    printf("The copied matrix:\n");
    for(int i = 0;i<4;i++){
        for(int j = 0;j<5;j++){
            printf("%f ",mat2[i][j]);
        }
        printf("\n");
    }
    return 0;
}