#include <stdio.h>

struct node{
    int data;
    int key;
    struct node* left;
    struct node* right;
};
struct node* root=NULL;
int temp,n;

struct node* balance(struct node*,int ,int );
struct node* leftrotate(struct node*);
struct node* rightrotate(struct node*);
struct node* insert(struct node* ,int );
int main(){
    int i;
    n=100000;
    for (i=0;i<n;i++){
        temp=i+1;
        root=insert(root,temp);
    }
    return 0;
}

struct node* insert(struct node* croot,int data){
    int l=0,r=0,diff;
    if (croot==NULL){
        struct node* temp=malloc(sizeof(struct node));
        temp->data=data;
        temp->left=temp->right=NULL;
        temp->key=0;
        return temp;
    }
    if (croot->data>data){
        croot->left=insert(croot->left,data);
    }
    else{
        croot->right=insert(croot->right,data);
    }
    if (croot->left!=NULL) l=(croot->left)->key;
    if (croot->right!=NULL) r=(croot->right)->key;
    diff=l>r?l-r:r-l;
    if (diff>=1){
        croot=balance(croot,l,r);
    }
    generatekey(croot);
    return croot;
}

struct node* balance(struct node* croot,int l,int r){
    if (r>l){
        if ((croot->right)->left!=NULL)
        if (((croot->right)->left)->key>((croot->right)->right)->key) croot->right=leftrotate(croot->right);
        croot=rightrotate(croot);
    }
    else{
        if ((croot->left)->right!=NULL)
        if (((croot->left)->right)->key>((croot->left)->left)->key) croot->left=rightrotate(croot->left);
        croot=leftrotate(croot);
    }
    return croot;
}

int generatekey(struct node* croot){
    if ((croot->left==NULL)&&(croot->right==NULL)) croot->key=0;
    else if (croot->left==NULL){
        croot->key=(croot->right)->key+1;
    }
    else if (croot->right==NULL){
        croot->key=(croot->left)->key+1;
    }
    else{
        croot->key=max((croot->left)->key,(croot->right)->key)+1;
    }
    return 0;
}

int max(int x,int y){
    return x>y?x:y;
}

int preorder(struct node* croot){
    if (croot==NULL) return 0;
    printf("%d ",croot->data);
    preorder(croot->left);
    preorder(croot->right);
    return 0;
}

struct node* rightrotate(struct node* croot){
    struct node* temp,* x;
    temp=croot;
    x=temp->right;
    temp->right=x->left;
    x->left=temp;
    generatekey(temp);
    return x;
}

struct node* leftrotate(struct node* croot){
    struct node* temp,* x;
    temp=croot;
    x=temp->left;
    temp->left=x->right;
    x->right=temp;
    generatekey(temp);
    return x;
}
