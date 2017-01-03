#include <bits/stdc++.h>
#define INF 1000000000000
#define MAX 100001
using namespace std;

int n,level[MAX],an[MAX][20];

vector < vector<int> > e;

int precompute(int node,int par,int a[],int h){
	for (vector<int>::iterator it = e[node].begin();it!=e[node].end();it++){
		if (*it!=par){
			a[h] = node;
			precompute(*it,node,a,h+1);
		}
	}
	level[node] = h;
	int p = 1,c = 0;
	while(h-p>=0){
		an[node][c++] = a[h-p];
		p*=2;
	}
	return 0;
}

int leveller(int x,int y){
	while(level[x]!=level[y]) x = an[x][int(log2(level[x]-level[y]))];
	return x;
}

int lca(int x,int y){
	int idx = log2(level[x]);
	while(idx>=0){
		if (an[x][idx]!=an[y][idx]){
			x = an[x][idx];
			y = an[y][idx];
		}
		idx--;
	}
	return an[x][0];
}

int main(){
	scanf("%d",&n);
	e.resize(n+1);
	for (int i=0;i<n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
		mp[make_pair(x,y)] = i;
		mp[make_pair(y,x)] = i;
	}
	int temp[MAX];
	precompute(1,0,temp,0);
	int m;
	scanf("%d",&m);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		if (level[x]<level[y]) swap(x,y);
		x = leveller(x,y);
		int l;
		if (x==y) l = x;
		else l = lca(x,y);
	}
	return 0;
}
