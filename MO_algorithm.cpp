#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000
#define M 1000000007
#define MAX 100000000
#define fori(l,r,x) for (int i=l;i<=r;i+=x)
#define forj(l,r,x) for (int j=l;j<=r;j+=x)
using namespace std;

//DQUERY SPOJ

int sq;

struct node{
	int a,b,index;
}query[200000];

bool operator <(node x,node y){
	return (x.a)/sq==(y.a)/sq?x.b<y.b:(x.a)/sq<(y.a)/sq;
}
int a[30001];

int cl=0,cr=0,prev=0,res[200000],mark[1000001];

int solve(int x){
	int l = query[x].a;
	int r = query[x].b;
	if (prev==0){
		fori(l,r,1) mark[a[i]]++;
		fori(1,1000000,1) if (mark[i]!=0) prev++;
		cl=l;cr=r;
		res[query[x].index] = prev;
		return 0;
	}
	while (cl<l){
		mark[a[cl]]--;
		if (mark[a[cl]]==0) prev--;
		cl++;
	}
	while (l<cl){
		cl--;
		mark[a[cl]]++;
		if (mark[a[cl]]==1) prev++;
	}
	while (cr>r){
		mark[a[cr]]--;
		if (mark[a[cr]]==0) prev--;
		cr--;
	}
	while (cr<r){
		cr++;
		mark[a[cr]]++;
		if (mark[a[cr]]==1) prev++;
	}
	res[query[x].index] = prev;
	return 0;
}

int main(){
	int n;
	scanf("%d",&n);
	sq = sqrt(n);
	fori(1,n,1) scanf("%d",&a[i]);
	int q,l,r;
	scanf("%d",&q);
	fori(0,q-1,1){
		scanf("%d%d",&l,&r);
		query[i].a = l;
		query[i].b = r;
		query[i].index = i;
	}
	sort(query,query+q);
	fori(0,q-1,1) solve(i);
	fori(0,q-1,1) printf("%d\n",res[i]);
	return 0;
}
