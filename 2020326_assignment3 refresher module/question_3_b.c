//assignment 3 question 3 part b
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    int height;
    struct node *left,*right;
};
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int height(struct node *root){
    if(root==NULL){
        return 0;
    }
    return root->height;
}
int balance(struct node*root){
    if(root==NULL){
        return 0;
    }
    return height(root->left) - height(root->right);
}
struct node *new_node(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=1;
    return temp;
}
struct node *rr(struct node*root){
    struct node *lefter=root->left;
    struct node*righter=lefter->right;
    lefter->right=root;
    root->left=righter;
    lefter->height=1+ max(height(lefter->right), height(lefter->left));
    root->height= 1+max(height(root->left), height(root->right));
    return lefter;
}
struct node*ll(struct node*root){
    struct node*righter=root->right;
    struct node*lefter=righter->left;
    righter->left=root;
    root->right=lefter;
    righter->height=1+ max(height(righter->right), height(righter->left));
    root->height=1+ max(height(root->left), height(root->right));
    return righter;
}
struct node *insertion(struct node*root,int data){
    if(root==NULL){
        struct node*temp= new_node(data);
        return temp;//new_node(data);
    }else if(root->data>data){
        root->left= insertion(root->left,data);
    } else if(root->data<data){
        root->right= insertion(root->right,data);
    } else{
        return root;
    }
    root->height = 1+ max(height(root->left), height(root->right));
    int bal= balance(root);
    if(bal>1){
        if(root->left->data>data){
            return rr(root);
        } else if(root->left->data<data){
            root->left= ll(root->left);
            return rr(root);
        }
    }else if(bal<-1){
        if(root->right->data>data){
            root->right=rr(root->right);
            return ll(root);
        } else if(root->right->data<data){
            return ll(root);
        }
    }
    return root;
}
struct node *deletion(struct node*root,int data){
    if(root==NULL){
        printf("this element is not in tree\n");
        return NULL;
    } else if(root->data>data){
        root->left= deletion(root->left,data);
    } else if(root->data<data){
        return root->right= deletion(root->right,data);
    } else{
        if(root->left==NULL){
            root=root->right;
        } else if(root->right==NULL){
            root=root->left;
        } else{
            struct node*temp=root->right;
            while (temp->left!=NULL){
                temp=temp->left;
            }
            root->data=temp->data;
            root->right= deletion(root->right,temp->data);
        }
    }
    if(root==NULL){
        return NULL;
    }
    root->height=1+ max(height(root->right), height(root->left));
    int bal= balance(root);
    if(bal>1){
        if(balance(root->left)>=0){
            return rr(root);
        } else{
            root->left= rr(root->left);
            return rr(root);
        }
    } else if(bal<-1){
        if(balance(root->right)>0){
            root->right= rr(root->right);
            return ll(root);
        } else{
            return ll(root);
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
    char max[10];
    int n;
    printf("please enter maximum no of operations you want to perform: ");
    scanf("%s",max);
    n= strtol(max,(char **)NULL,10);
    for (int i = 0; i < n; ++i) {
        char choice[1];
        int c;
        printf("\nenter 0 if you want to perform insertion,\n1 if you want to perform deletion,\n2 to print the contents of avl tree in ascending order");
        scanf("%s",choice);
        c= strtol(choice,(char **)NULL,10);
        char noder[10];
        int nodet;
        if(c==0){
            printf("\nenter the value of the node to be inserted:");
            scanf("%s",noder);
            nodet= strtol(noder,(char **)NULL,10);
            root=insertion(root,nodet);
        } else if(c==1){
            printf("\nenter the value of node to be deleted:");
            scanf("%s",noder);
            nodet= strtol(noder,(char **)NULL,10);
            root=deletion(root,nodet);
        }else if(c==2) {
            inorder_print(root);
        }else{
            printf("incorrect choice");
        }
    }
    return 0;
}