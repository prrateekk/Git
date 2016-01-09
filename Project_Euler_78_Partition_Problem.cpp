#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000
#define M 1000000
#define MAX 100000
#define X 6
#define set(x,y) memset(x,y,sizeof(x))
#define fori(l,r,x) for (ll int i=l;i<=r;i+=x)
#define forj(l,r,x) for (ll int j=l;j<=r;j+=x)
using namespace std;

//MACMOHAN RECURRENCE RELATION OF PENTAGONAL NUMBERS
//http://mathworld.wolfram.com/PartitionFunctionP.html

int p[MAX+1];

int init(){
	p[0]=1;
	p[1]=1;
	p[2]=2;
	int x = 3;
	while(x<MAX){
		int i=1;
		int sn=1;
		while(1){
			int t = i;
			int pen = (i*(3*i-1))/2;
			if (pen>x) break;
			p[x] = (p[x]+sn*p[x-pen])%1000000;
			i*=-1;
			pen = (i*(3*i-1))/2;
			if (pen>x) break;
			p[x] = (p[x]+sn*p[x-pen])%1000000;
			i=t;
			i++;
			sn*=-1;
		}
		if (p[x]==0){
			cout << x << endl;
			break;
		}
		x++;
	}
	return 0;
}

int main(){
	clock_t tStart = clock();
	init();
	printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
