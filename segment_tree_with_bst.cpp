//============================================================================
// Author      : Prateek Agarwal
// Institution : NITJ
//============================================================================

#include <bits/stdc++.h>

#define ll long long

#define TEST int t;scan(t);while(t--)
#define scan(n) scanf("%d",&n)
#define set(x,y) memset(x,y,sizeof(x))
#define loop(i,l,r,x) for (int i=l;i<=r;i+=x)
#define printl(n) printf("%d\n",n)
#define print(n) printf("%d ",n)
#define pb push_back

#define INF 1000000000
#define M 1000000009
#define MAX 10001
#define LIM 10

using namespace std;

int n,a[100000];

struct node{
	int v,l,r;
	node *left,*right;
};

node *seg[1000000];

node* getnode(int v){
	node *temp = new node();
	temp->v = v;
	temp->l = temp->r = 0;
	return temp;
}

int add_node(int v,node* croot){
	if (v>croot->v){
		croot->r++;
		if (croot->right==NULL){
			(croot->right) = getnode(v);
			return 0;
		}
		else add_node(v,croot->right);
	}
	else{
		croot->l++;
		if (croot->left==NULL){
			(croot->left) = getnode(v);
			return 0;
		}
		else add_node(v,croot->left);
	}
	return 0;
}

int build_bst(int i,int l,int r){
	node *temp = new node();
	temp->v = a[l];
	temp->l = temp->r = 0;
	seg[i] = temp;
	loop(j,l+1,r,1){
		add_node(a[j],seg[i]);
	}
	return 0;
}

int build_seg(int i,int l,int r){
	if (l==r){
		build_bst(i,l,r);
		return 0;
	}
	int left = 2*i+1;
	int right = left+1;
	int mid = (l+r)>>1;
	build_seg(left,l,mid);
	build_seg(right,mid+1,r);
	build_bst(i,l,r);
	return 0;
}

//counts values <= k
int count(node* root,int k){
	node *temp = root;
	int c = 0;
	while(temp!=NULL){
		if (temp->v<=k){
			c+=(temp->l+1);
			temp = temp->right;
		}
		else{
			temp = temp->left;
		}
	}
	return c;
}

int query(int i,int l,int r,int x,int y,int k){
	if (l>r) return 0;
	if (l>y||r<x) return 0;
	if (x<=l&&y>=r) return count(seg[i],k);
	int left = 2*i+1;
	int right = left+1;
	int mid = (l+r)>>1;
	return query(left,l,mid,x,y,k)+query(right,mid+1,r,x,y,k);
}

int init(){
	int q;
	scan(n);
	scan(q);
	loop(i,0,n-1,1) scan(a[i]);
	build_seg(0,0,n-1);
	while(q--){
		int a,b,c;
		scan(a);
		scan(b);
		a--;
		b--;
		scan(c);
		printl(query(0,0,n-1,a,b,c));
	}
	return 0;
}

int main(){
	//clock_t start = clock();
	init();
	//printf("%.6f\n",double(clock()-start)/CLOCKS_PER_SEC);
	return 0;
}
