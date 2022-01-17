//assignment 2 question 2 part c queues
#include <stdlib.h>
#include <stdio.h>
struct node{
    int data;
    struct node*next;
};
struct node*new_node(int data){
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
struct node *head,*tail;
void initialise(){
    head=NULL;
    tail=NULL;
}
void enqueue(int data){
    struct node*temp= new_node(data);
    if(tail==NULL){
        head=tail=temp;
        return;
    }
    tail->next=temp;
    tail=temp;
}
int dequeue(){
    if(head==NULL){
        printf("queue is empty, cannot dequeue element");
        return -1;
    }
    int n=head->data;
    head=head->next;
    if(head==NULL){
        tail=NULL;
    }
    return n;
}
void queue_print(){
    struct node*temp=head;
    while (temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int peek(){
    if(head==NULL){
        printf("error queue is empty");
        return -1;
    }
    return head->data;
}
int main(){
    initialise();
    char max[10];
    int n;
    printf("enter maximum number of operations to be performed on the queue:");
    scanf("%s",max);
    n= strtol(max,(char **)NULL,10);
    for (int i = 0; i < n; ++i) {
        char c[1];
        int choice;
        char datar[10];
        int data;
        printf("enter 0 to add value to queue,\n1 to delete value from queue,\n2 to find value at top of queue,\n3 to print all values in queue:");
        scanf("%s",c);
        choice= strtol(c,(char **)NULL,10);
        if(choice==0){
            printf("enter data to add to queue:");
            scanf("%s",datar);
            data= strtol(datar,(char **)NULL,10);
            enqueue(data);
        } else if(choice==1){
            printf("the data removed from queue is: %d\n",dequeue());
        } else if(choice==2){
            printf("the data at top of the queue is: %d\n",peek());
        } else if(choice==3){
            printf("all the elements in the queue are:\n");
            queue_print();
        } else{
            printf("incorrect choice was input, please try again");
        }
    }
    return 0;
}