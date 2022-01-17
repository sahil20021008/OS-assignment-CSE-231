//assignment 2 question 2 part c stacks
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
struct node{
    int data;
    struct node*next;
};
struct node *head;
void initialise(){
    head=NULL;
}
struct node*new_node(int data){
    struct node*temp=(struct node*) malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
bool isEmpty(){
    return head==NULL;
}
void push(int data){
    struct node*temp= new_node(data);
    temp->next=head;
    head=temp;
}
int pop(){
    if(isEmpty()){
        printf("error: stack is empty\n");
        return -1;
    }
    int n=head->data;
    head=head->next;
    return n;
}
int top(){
    if(head==NULL){
        return -1;
    }
    return head->data;
}
void stackprint(){
    struct node*temp=head;
    while (temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    initialise();
    int n;
    char ope[10];
    printf("enter no of operations to be performed on stack:");
    scanf("%s",ope);
    n= strtol(ope,(char **)NULL,10);
    for (int i = 0; i < n; ++i) {
        char c[1];
        int choice;
        char d[10];
        int datar;
        printf("enter 0 to push a value,\n1 to pop value,\n2 to see value at top of stack,\n3 to print all elements of stack\n");
        scanf("%s", c);
        choice = strtol(c, (char **) NULL, 10);
        if (choice == 0) {
            printf("enter data to be pushed to stack:");
            scanf("%s",d);
            datar= strtol(d,(char **)NULL,10);
            push(datar);
        } else if (choice == 1) {
            printf("the value that was popped is:%d\n",pop());
        } else if (choice == 2) {
            printf("the value at top of stack is: %d\n",top());
        } else if (choice == 3) {
            printf("all values in the stack are:\n");
            stackprint();
        } else {
            printf("incorrect choice entered: please try again\n");
        }
    }
    return 0;
}