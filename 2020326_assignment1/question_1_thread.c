#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <string.h>
void * sub(){
   int input=open("student_record.csv",O_RDONLY);
   if(input==-1){
       printf("error: file wasn't opened");
       return NULL;
   }
   lseek(input,0,SEEK_SET);
   char array[2000];
   read(input, array, sizeof(array));
   close(input);
   int delta=0;
   bool sect=false;
   double arr[]={0,0,0,0,0,0};
   char *temp= strtok(array,",");
   while (temp){
       if(strcmp(temp,"A")==0){
           sect=true;
           delta++;
       } else{
           sect=false;
       }
       if(sect==true){
           temp= strtok(NULL,",");
           arr[0]+= strtol(temp,NULL,10);
           temp= strtok(NULL,",");
           arr[1]+= strtol(temp,NULL,10);
           temp= strtok(NULL,",");
           arr[2]+= strtol(temp,NULL,10);
           temp= strtok(NULL,",");
           arr[3]+= strtol(temp,NULL,10);
           temp= strtok(NULL,",");
           arr[4]+= strtol(temp,NULL,10);
           temp= strtok(NULL,",");
           arr[5]+= strtol(temp,NULL,10);
       }
       temp= strtok(NULL,",");
   }
   printf("section A:\n");
   for (int i = 0; i < 6; ++i) {
       printf("the average marks in assignment %d are: %f\n",i+1,arr[i]/delta);
   }
   return NULL;
}
int main(){
   pthread_t child;
   pthread_create(&child,NULL,sub,NULL);
   pthread_join(child,NULL);
   int input=open("student_record.csv",O_RDONLY);
   if(input==-1){
       printf("error: file wasn't opened");
       return -1;
   }
   lseek(input,0,SEEK_SET);
   char array[2000];
   read(input,array, sizeof(array));
   close(input);
   int delta=0;
   bool sect=false;
   double arr[]={0,0,0,0,0,0};
   char *temp= strtok(array,",");
   while (temp){
       if(strcmp(temp,"B")==0){
           sect=true;
           delta++;
       } else{
           sect=false;
       }
       if(sect==true){
           temp= strtok(NULL,",");
           arr[0]+= strtol(temp,NULL,10);
           temp= strtok(NULL,",");
           arr[1]+= strtol(temp,NULL,10);
           temp= strtok(NULL,",");
           arr[2]+= strtol(temp,NULL,10);
           temp= strtok(NULL,",");
           arr[3]+= strtol(temp,NULL,10);
           temp= strtok(NULL,",");
           arr[4]+= strtol(temp,NULL,10);
           temp= strtok(NULL,",");
           arr[5]+= strtol(temp,NULL,10);
       }
       temp= strtok(NULL,",");
   }
   printf("section B:\n");
   for (int i = 0; i < 6; ++i) {
       printf("the average marks in assignment %d are: %f\n",i+1,arr[i]/delta);
   }
}