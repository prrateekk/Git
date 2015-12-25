#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000
#define M 1000000007
#define MAX 1000000
#define fori(l,r,x) for (int i=l;i<=r;i+=x)
#define forj(l,r,x) for (int j=l;j<=r;j+=x)
using namespace std;

//Eulier totient function using seive

int phi[MAX+1];

int seive_euler(){
	fori(2,MAX,1){
		if (!phi[i]){
			phi[i]=i-1;
			forj(i<<1,MAX,i){
				if (!phi[j]) phi[j]=j;
				phi[j]-=(phi[j]/i);
			}
		}
	}
	return 0;
}

int main(){
	clock_t tStart = clock();
	seive_euler();
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
