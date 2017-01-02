#include <bits/stdc++.h>
#define INF 1000000000000
using namespace std;

struct point{
	int x,y;
};

bool operator <(point a,point b){
	return (a.x==b.x?a.y<b.y:a.x<b.x);
}

//negative for convex
long long int cross_product(point o,point a,point b){
	return (long long int)(a.x-o.x)*(long long int)(b.y-o.y)-(long long int)(a.y-o.y)*(long long int)(b.x-o.x);
}

int main(){
	int m;
	scanf("%d",&m);
	point q[n];
	for (int i=0;i<n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	sort(q,q+m);

	point U[m],L[m];
	int uc = -1;
	U[++uc] = q[0];
	U[++uc] = q[1];
	for (int i=2;i<m;i++){
		while(uc>0 && cross_product(U[uc-1],U[uc],q[i])>0) uc--;
		U[++uc] = q[i];
	}

	int lc = -1;
	L[++lc] = q[m-1];
	L[++lc] = q[m-2];
	for (int i=m-3;i>=0;i--){
		while(lc>0 && cross_product(L[lc-1],L[lc],q[i])>0) lc--;
		L[++lc] = q[i];
	}

	return 0;
}
