#include <stdio.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* insert(struct node*,int);

int main(){
    struct node* root=NULL;
    root = insert(root,1);
    root = insert(root,3);
    root = insert(root,7);
    root = insert(root,4);
    root = insert(root,2);
    root = insert(root,8);
    root = insert(root,6);
    print(root);
    printf("\n%d",height(root));
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
    if (root==NULL) return -1;
    else{
        printf("%d ",root->data);
        print(root->left);
        print(root->right);
    }
}

int height(struct node* root){
    if (root==NULL) return -1;
    else return height(root->left)>height(root->right)?height(root->left)+1:height(root->right)+1;
}
