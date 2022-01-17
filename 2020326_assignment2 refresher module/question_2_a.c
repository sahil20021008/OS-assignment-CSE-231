//assignment 2 question 2 part a
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
struct student_records{
    char name[100];
    int roll_no;
    int year;
    char academic_program[200];
    struct student_records *next;
};
struct student_records*new_student(char n[100],int roll,int year,char academic_program[200]){
    struct student_records*temp=(struct student_records*)malloc(sizeof(struct student_records));
    temp->next=NULL;
    temp->year=year;
    temp->roll_no=roll;
    strcpy(temp->academic_program,academic_program);
    strcpy(temp->name,n);
    return temp;
}
void search_by_roll_no(struct student_records*curr,int roll_no){
    if(curr==NULL){
        printf("the student is not in records");
        return;
    }
    if(curr->roll_no==roll_no){
        printf("name: %s\nroll number: %d\nyear: %d\nacademic program: %s\n",curr->name,curr->roll_no,curr->year,curr->academic_program);
        return;
    }
    search_by_roll_no(curr->next,roll_no);
}
struct student_records*insert(struct student_records*head,char n[100],int roll,int year,char academic_program[200]){
    if(head==NULL){
        return new_student(n,roll,year,academic_program);
    }
    struct student_records*temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next= new_student(n,roll,year,academic_program);
    return head;
}
void print(struct student_records*temp){
    if(temp==NULL){
        return;
    }
    printf("name: %s, roll number: %d, year: %d, academic program: %s\n",temp->name,temp->roll_no,temp->year,temp->academic_program);
    print(temp->next);
}
struct student_records*delete(struct student_records*head,int roll) {
    if (head == NULL) {
        return head;
    }
    struct student_records *temp = head, *prev = NULL;
    if (head->roll_no == roll) {
        head = head->next;
        return head;
    }
    while (temp != NULL && temp->roll_no != roll) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("student is not in the records\n");
    }
    return head;
}
//struct student_records*delete(struct student_records*head,int roll){
//    if(head==NULL){
//        return head;
//    }
//    struct student_records*temp=head;
//    if(head->roll_no==roll){
//        head=head->next;
//        return head;
//    }
//    while (temp!=NULL&& temp->roll_no!=roll){
//        temp=temp->next;
//    }
//    if(temp!=NULL){
//        struct student_records*temper=temp->next;
//        temp->next=temp->next->next;
//        free(temper);
//    } else{
//        printf("student is not in records\n");
//    }
//    return head;
//}
int main(){
    char length[10];
    int n;
    struct student_records*head=NULL;
    printf("enter no of operations you want to perform:");
    scanf("%s",length);
    n= strtol(length,(char **)NULL,10);
    for (int i = 0; i < n; ++i) {
        char c[1];
        printf("\nenter 0 to insert records in list, 1 to delete, 2 to search for particular element or 3 to print entire list\n");
        scanf("%s",c);
        int choice= strtol(c,(char **)NULL,10);
        char name[100];
        char roller[10];
        int roll_no;
        int year;
        char yeare[10];
        char academic_program[200];
        if(choice==0){
            printf("enter name of student and press enter:");
            scanf("%s",name);
            printf("\nenter roll no:");
            scanf("%s",roller);
            roll_no= strtol(roller,(char **)NULL,10);
            printf("\nenter year:");
            scanf("%s",yeare);
            year= strtol(yeare,(char **)NULL,10);
            printf("\nenter the academic program and press enter:");
            scanf("%s",academic_program);
            head= insert(head,name,roll_no,year,academic_program);
        } else if(choice==1){
            printf("enter roll number of student whose records are to be deleted:");
            scanf("%s",roller);
            roll_no= strtol(roller,(char **)NULL,10);
            delete(head,roll_no);
        } else if(choice==2){
            printf("enter roll number of student:");
            scanf("%s",roller);
            roll_no= strtol(roller,(char **)NULL,10);
            search_by_roll_no(head,roll_no);
        } else if(choice==3){
            print(head);
        } else{
            printf("choice entered was incorrect. Please try again");
        }
    }
    return 0;
}
