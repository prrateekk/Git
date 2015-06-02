#include <stdio.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* insert(struct node*,int);

int main(){
    struct node* root=NULL;
    root = insert(root,5);
    root = insert(root,3);
    root = insert(root,7);
    root = insert(root,4);
    root = insert(root,2);
    root = insert(root,8);
    root = insert(root,6);
    print(root);
    printf("\n%d",min(root));
    printf("\n%d",max(root));
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
int print(struct node* root){
    if (root==NULL) return 0;
    else{
        printf("%d ",root->data);
        print(root->left);
        print(root->right);
    }
}

int min(struct node* root){
    if (root->left==NULL) return root->data;
    else min(root->left);
}
int max(struct node* root){
    if (root->right==NULL) return root->data;
    else max(root->right);
}
