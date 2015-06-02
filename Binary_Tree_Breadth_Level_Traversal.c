#include <stdio.h>
struct node{        //Node for Binary tree
    int data;
    struct node* left;
    struct node* right;
};
struct node* insert(struct node*,int);

struct lnode{       //Node for a linked list for making a queue
    struct node* data;
    struct lnode* next;
};
struct lnode* head;
struct lnode* rear;

struct node* insert(struct node*,int);
int level_traverse(struct node*);
int is_empty();

int main(){
    struct node* root=NULL;
    head=NULL;
    rear=NULL;
    int n,i,x;
    printf("Enter the number of elements in the tree:");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for (i=0;i<n;i++){
        scanf("%d",&x);
        root=insert(root,x);
    }
    level_traverse(root);
    return 0;
}
struct node* insert(struct node* root,int x){
    if (root==NULL) {
        struct node* temp = malloc(sizeof(struct node));
        temp->data = x;
        temp->right = NULL;
        temp->left = NULL;
        return temp;
    }
    else if (root->data > x) root->left = insert(root->left,x);
    else root->right = insert(root->right,x);
    return root;
}

int enqueue(struct node* x){
    struct lnode* temp=malloc(sizeof(struct lnode));
    temp->data = x;
    temp->next = NULL;
    if (head==NULL){
        head=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
    return 0;
}

int dequeue(){
    if (is_empty==1) rear=NULL;
    else{
        struct lnode* temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}

int level_traverse(struct node* root){
    if (root!=NULL) enqueue(root);
    while (is_empty()!=1){
        printf("%d ",(head->data)->data);
        if ((head->data)->left!=NULL)
        enqueue((head->data)->left);
        if ((head->data)->right!=NULL)
        enqueue((head->data)->right);
        dequeue();
    }
    return 0;
}

int is_empty(){
    if (head==NULL)
        return 1;
    else
        return 0;
}
