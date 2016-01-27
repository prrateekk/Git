#include <bits/stdc++.h>
#define ll long long
#define scan(n) scanf("%d",&n)
#define INF 1000000000000
#define M 1000000
#define MAX 10000000
#define X 6
#define set(x,y) memset(x,y,sizeof(x))
#define fori(l,r,x) for (int i=l;i<=r;i+=x)
#define forj(l,r,x) for (int j=l;j<=r;j+=x)
using namespace std;

int n,a[MAX+1];

int func(){
	int index = 0;
	for(int i=31;i>=0;i--){
		int mx_in=-1;
		forj(index,n-1,1) if ((a[j]&(1<<i))&&a[j]>a[mx_in]) mx_in = j;
		if (mx_in==-1) continue;
		forj(0,n-1,1) if (j!=mx_in&&(a[j]&(1<<i))) a[j]^=a[mx_in];
		swap(a[index],a[mx_in]);
		index++;
	}
	fori(1,n-1,1) a[0]^=a[i];
	return a[0];
}

int init(){
	int t;
	scan(t);
	while(t--){
		scan(n);
		fori(0,n-1,1) scan(a[i]);
		cout << func() << endl;
	}
	return 0;
}

int main(){
	//clock_t tStart = clock();
	init();
	//printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
