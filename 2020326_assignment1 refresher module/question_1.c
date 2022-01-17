//assignment 1 q 1
#include <stdio.h>
int main(){
    FILE *input,*output;
    char inputt[1000],outputt[1000];
    printf("enter input file name:");
    scanf("%s",inputt);
    printf("enter output file name:");
    scanf("%s",outputt);
    input= fopen(inputt,"rb");//opening files
    output= fopen(outputt,"wb");
    if(input==NULL||output==NULL){//checking if files were opened
        printf("error: no such file or directory");
        return 1;
    }
    fseek(input,0,SEEK_END);
    int size= ftell(input);//finding size of the file
    fseek(input,0,SEEK_SET);
    char text[size];
    fread(text, sizeof(char ),size/ sizeof(char ),input);//reading from input file
    fwrite(text, sizeof(char ),size/ sizeof(char ),output);//writing into output file
    fseek(output,0,SEEK_SET);
    fclose(input);//closing both files
    fclose(output);
    return 0;//end of main function
}
