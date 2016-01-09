#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000
#define M 1000000007
#define MAX 1300
#define X 6
#define set(x,y) memset(x,y,sizeof(x))
#define fori(l,r,x) for (ll int i=l;i<=r;i+=x)
#define forj(l,r,x) for (ll int j=l;j<=r;j+=x)
using namespace std;

int mark[1500001];

int markall(int x){
	int i=1;
	while(1){
		if (i*x>1500000) break;
		mark[i*x]++;
		i++;
	}
	return 0;
}

int init(){
	for(int m=1;m<=1300;m++){
		for(int n=m+1;n<=1300;n++){
			int x=0;
			if (m%2==0)x++;
			if (n%2==0)x++;
			if (x==0||x==2||__gcd(m,n)!=1) continue;
			int a = n*n-m*m;
			int b = 2*m*n;
			int c = n*n+m*m;
			markall(a+b+c);
		}
	}
	int c=0;
	fori(1,1500000,1) if (mark[i]==1) c++;
	cout << c << endl;
	return 0;
}

int main(){
	clock_t tStart = clock();
	init();
	printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
