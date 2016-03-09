//============================================================================
// Name        : optimised_bitwise_sieve.cpp
// Author      : Prateek Agarwal
// Institution : NIT Jalandhar
//============================================================================

#include <bits/stdc++.h>
using namespace std;

#define MAX 100000000
#define SQ 10000

#define check(n) (prime[n>>6]&(1<<((n&63)>>1)))
#define set(n) prime[n>>6]|=(1<<((n&63)>>1))

int prime[MAX>>6];

vector<int> x;

int sieve(){
	int c  = 0;
	for(int i=3;i<=SQ;i+=2){
		if (!check(i)){
			int inc = 2*i;
			for(int j=i*i;j<=MAX;j+=inc){
				set(j);
			}
		}
	}

	for(int i=1;i<100000000;i+=2){
		if (!check(i)){
			x.push_back(i);
			c++;
			if (c==5000000) break;
		}
	}

	int q;
	scanf("%d",&q);
	while(q--){
		int n;
		scanf("%d",&n);
		if (n==1) cout << 2 << endl;
		else cout << x[n-1] << endl;
	}
	return 0;
}

int main(){
	sieve();
	return 0;
}
