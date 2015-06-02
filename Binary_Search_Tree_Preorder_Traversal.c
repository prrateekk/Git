#include <stdio.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root;

int main(){
    root = NULL;
    int n,x,i;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for (i=0;i<n;i++){
        scanf("%d",&x);
        root = insert(root,x);
    }
    traversal(root);
    return 0;
}

int insert(struct node* root,int x){
    if (root==NULL){
        struct node* temp = malloc(sizeof(struct node));
        temp->data = x;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    else if (x > root->data) root->right = insert(root->right,x);
    else root->left = insert(root->left,x);
    return root;
}

int traversal(struct node* root){       //Preorder
    if (root==NULL)
    return 0;
    else{
        printf("%d ",root->data);
        traversal(root->left);
        traversal(root->right);
    }
}
