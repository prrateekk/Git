#include <bits/stdc++.h>
using namespace std;

int a[200000];

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node* root;

struct node* maketree(int l,int r){
	if (l==r){
		struct node* temp = new node();
		temp->data = a[l];
		temp->left = temp->right = NULL;
		return temp;
	}
	int mid = (l+r)/2;
	struct node* croot = new node();
	croot->left = maketree(l,mid);
	croot->right = maketree(mid+1,r);
	croot->data = ((croot->left)->data)&((croot->right)->data);
	return croot;
}

int query(struct node* croot,int l,int r,int x,int y){
	if (l>r) return 1;
	int mid = (l+r)/2;
	if (l>=x&&r<=y) return croot->data;
	else if (r<x||l>y) return 1;
	else return (query(croot->left,l,mid,x,y)&query(croot->right,mid+1,r,x,y));
}

/*
int display(struct node* croot){
	if (croot==NULL) return 0;
	display(croot->left);
	cout << croot->data << endl;
	display(croot->right);
}
*/

int printall(int n){
	int data = root->data;
	for (int i=0;i<n;i++)
		cout << data << " ";
	cout << endl;
	return 0;
}

int main(){

	return 0;
}
