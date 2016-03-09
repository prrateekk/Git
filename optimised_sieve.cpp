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

int sieve(){
	for(int i=3;i<=SQ;i+=2){
		if (!check(i)){
			int inc = 2*i;
			for(int j=i*i;j<=MAX;j+=inc){
				set(j);
			}
		}
	}
	return 0;
}

int main(){
	//clock_t start = clock();
	sieve();
	//printf("%.6f\n",double(clock()-start)/CLOCKS_PER_SEC);
	return 0;
}
