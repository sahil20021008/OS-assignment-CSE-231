//assignment 2 question 2 part b
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct doubly_student_records{
    char name[100];
    int roll_no;
    int year;
    char academic_program[200];
    struct doubly_student_records *prev;
    struct doubly_student_records *next;
};
struct doubly_student_records*new_node(char n[100],int roll,int year,char academic_program[200]){
    struct doubly_student_records*temp=(struct doubly_student_records*)malloc(sizeof(struct doubly_student_records));
    strcpy(temp->name,n);
    strcpy(temp->academic_program,academic_program);
    temp->prev=NULL;
    temp->next=NULL;
    temp->roll_no=roll;
    temp->year=year;
    return temp;
}
struct doubly_student_records*insertion(struct doubly_student_records*head,char n[100],int roll,int year,char academic_program[100]){
    if(head==NULL){
        return new_node(n,roll,year,academic_program);
    }
    struct doubly_student_records*temp=new_node(n,roll,year,academic_program);
    head->prev=temp;
    temp->next=head;
    head=temp;
    return head;
}
struct doubly_student_records*deletion(struct doubly_student_records*head,int roll){
    if(head==NULL){
        return NULL;
    }
    struct doubly_student_records*temp=head;
    while (temp!=NULL&&temp->roll_no!=roll){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("student with that roll number is not in directory");
    }else if(temp->prev==NULL&&temp->next==NULL){
        return NULL;
    } else if(temp->prev==NULL){
        temp->next->prev=NULL;
        head=temp->next;
    } else if(temp->next==NULL){
        temp->prev->next=NULL;
    } else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    return head;
}
void search_by_roll_no(struct doubly_student_records*curr,int roll_no){
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
void record_print(struct doubly_student_records*head){
    struct doubly_student_records*temp=head;
    if(head==NULL){
        printf("records are empty");
    }
    while (temp!=NULL){
        printf("name:%s,\nroll number:%d,\nyear:%d,\nacademic program:%s\n",temp->name,temp->roll_no,temp->year,temp->academic_program);
        temp=temp->next;
    }
}
int main(){
    struct doubly_student_records*head=NULL;
    char length[10];
    int n;
    printf("enter maximum no of operations to perform:");
    scanf("%s",length);
    n= strtol(length,(char **)NULL,10);
    for (int i = 0; i < n; ++i) {
        char name[100];
        char academic_program[200];
        char roller[20];
        int roll;
        int year;
        char yeare[20];
        char choice[1];
        int c;
        printf("\nenter 0 to insert records in list, 1 to delete, 2 to search for particular element or 3 to print entire list\n");
        scanf("%s",choice);
        c= strtol(choice,(char **)NULL,10);
        if(c==0){
            printf("enter name of student and press enter:");
            scanf("%s",name);
            printf("\nenter roll no:");
            scanf("%s",roller);
            roll= strtol(roller,(char **)NULL,10);
            printf("\nenter year:");
            scanf("%s",yeare);
            year= strtol(yeare,(char **)NULL,10);
            printf("\nenter the academic program and press enter:");
            scanf("%s",academic_program);
            head= insertion(head,name,roll,year,academic_program);
        } else if(c==1){
            printf("enter roll number of student whose records are to be deleted:");
            scanf("%s",roller);
            roll= strtol(roller,(char **)NULL,10);
            head= deletion(head,roll);
        } else if(c==2){
            printf("enter roll number of student:");
            scanf("%s",roller);
            roll= strtol(roller,(char **)NULL,10);
            search_by_roll_no(head,roll);
        } else if(c==3){
            printf("the student records are:\n");
            record_print(head);
        } else{
            printf("incorrect choice input, please try again\n");
        }
    }
    return 0;
}
