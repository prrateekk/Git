#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000
#define forni for (int i=0;i<n;i++)
#define fornj for (int j=0;j<n;j++)
using namespace std;

struct node{
	int cn;
	struct node* child[256];
};

int insert(struct node* croot,char s[]){
	int l = strlen(s),i=0;
	while (i<l){
		if (croot->child[int(s[i])]==NULL){
			struct node* temp = new node();
			croot->child[int(s[i])] = temp;
		}
		croot = croot->child[int(s[i])];
		i++;
	}
	if (croot->child[0]==NULL){
		struct node* temp = new node();
		croot->child[0] = temp;
	}
	croot->cn++;
	return 0;
}

char st[50];
int top;

int display(struct node* croot){
	if (croot->child[0]!=NULL)for(int i=0;i<croot->cn;i++)printf("%s\n",st);
	for (int i=0;i<256;i++){
		if (croot->child[i]!=NULL){
			st[top++] = char(i);
			display(croot->child[i]);
			top--;
		}
	}
	return 0;
}

int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		struct node* root = new node();
		int n;
		char temp[50];
		scanf("%d",&n);
		top=0;
		forni{
			scanf("%s",temp);
			insert(root,temp);
		}
		display(root);
	}
	return 0;
}
