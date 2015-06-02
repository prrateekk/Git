#include <stdio.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root;
int val=-65535,flag=0;
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
    if (flag==0) printf("BST!\n");
    else printf("Not BST!\n");
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
    root->left = insert(root->left,x);
    root->right = insert(root->right,x);
    return root;
}

int traversal(struct node* root){   //Inorder
    if (root==NULL)
    return 0;
    else{
        traversal(root->left);
        if (root->data > val){
            val=root->data;
        }
        else{
            flag=1;
            return 0;
        }
        traversal(root->right);
    }
}
