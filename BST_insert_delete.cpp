//============================================================================
// Author      : Prateek Agarwal
// Institution : NITJ
// Description : BST implementation
//============================================================================

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

struct node{
	int data;
	node *left,*right;
};

node *root;

int clear(){
	root = NULL;
	return 0;
}

int traverse(node *croot){
	if (!croot) return 0;
	traverse(croot->left);
	cout << croot->data << " ";
	traverse(croot->right);
	return 0;
}

int display(node *croot){
	cout << "Tree:";
	traverse(croot);
	cout << endl;
	return 0;
}

node *getnode(int x){
	node *temp = new node();
	temp->data = x;
	temp->left = temp->right = NULL;
	return temp;
}

node *insert(node *croot,int x){
	if (croot==NULL) return getnode(x);
	if (croot->data > x) croot->left = insert(croot->left,x);
	else croot->right = insert(croot->right,x);
	return croot;
}

node *delete_node(node *croot,int x){
	if (!croot) return NULL;
	if (croot->data==x){
		if (!croot->left && !croot->right) return NULL;
		else if (croot->left && croot->right){
			node *temp = croot->right;
			while(temp->left) temp = temp->left;
			int q = croot->data;
			croot->data = temp->data;
			temp->data = q;
			croot->right = delete_node(croot->right,q);
			return croot;
		}
		else if (croot->left){
			croot->data = croot->left->data;
			croot->left = NULL;
			return croot;
		}
		else{
			croot->data = croot->right->data;
			croot->right = NULL;
			return croot;
		}
	}
	else if (croot->data > x) croot->left = delete_node(croot->left,x);
	else croot->right = delete_node(croot->right,x);
	return croot;
}

int height(node *croot){
	if (!croot) return 0;
	return max(height(croot->left),height(croot->right))+1;
}

int main(){
	clear();
	display(root);
	root = insert(root,5);
	display(root);
	root = insert(root,7);
	display(root);
	root = insert(root,12);
	display(root);
	root = insert(root,1);
	display(root);
	root = insert(root,3);
	display(root);
	root = insert(root,4);
	display(root);
	root = insert(root,13);
	display(root);
	root = delete_node(root,13);
	display(root);
	cout << height(root);
	return 0;
}
