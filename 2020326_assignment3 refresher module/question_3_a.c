//assignment 3 question 3 part a
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left, *right;
};
struct node*new_node(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node*insertion(struct node*root,int data){
    if(root==NULL){
        return new_node(data);
    }else if(root->data>data){
        root->left= insertion(root->left,data);
    } else{
        root->right= insertion(root->right,data);
    }
    return root;
}
struct node*deletion(struct node*root,int data){
    if(root==NULL){
        printf("this element is not in tree");
        return NULL;
    } else if(root->data>data){
        root->left= deletion(root->left,data);
    } else if(root->data<data){
        root->right= deletion(root->right,data);
    } else{
        if(root->left==NULL){
            return root->right;
        } else if(root->right==NULL){
            return root->left;
        } else{
            struct node*temp=root->right;
            while (temp->left!=NULL){
                temp=temp->left;
            }
            root->data=temp->data;
            root->right= deletion(root->right,temp->data);
        }
    }
    return root;
}
void inorder_print(struct node*root){
    if(root==NULL){
        return;
    }
    inorder_print(root->left);
    printf("%d ",root->data);
    inorder_print(root->right);
}
int main(){
    struct node *root = NULL;
    printf("enter the maximum number of operations in bst: ");
    int n;
    char max[10];
    scanf("%s",max);
    n= strtol(max,(char **)NULL,10);
    for (int i = 0; i < n; ++i) {
        char choice[1];
        int c;
        printf("\nenter 0 if you want to perform insertion, 1 if you want to perform deletion,\n2 for inorder print of bst");
        scanf("%s",choice);
        c= strtol(choice,(char **)NULL,10);
        int data;
        char datar[10];
        if(c==0){
            printf("enter data to be added to bst:");
            scanf("%s",datar);
            data= strtol(datar,(char **)NULL,10);
            root= insertion(root,data);
        } else if(c==1){
            printf("enter data to be deleted from bst:");
            scanf("%s",datar);
            data= strtol(datar,(char **)NULL,10);
            root= deletion(root,data);
        } else if(c==2){
            printf("the inorder print of bst is:\n");
            inorder_print(root);
        } else{
            printf("error incorrect input, try again\n");
        }
    }
    return 0;
}

