//============================================================================
// Name        : optimised_bitwise_sieve.cpp
// Author      : Prateek Agarwal
// Institution : NIT Jalandhar
//============================================================================

#include <bits/stdc++.h>
using namespace std;

#define MAX 100000000
#define SQ 10000

bitset<MAX> m;

int sieve(){
	for(int i=3;i<=SQ;i+=2){
		if (!m[i]){
			int inc = 2*i;
			for(int j=i*i;j<=MAX;j+=inc){
				m[j]=1;
			}
		}
	}
	return 0;
}

int main(){
	clock_t start = clock();
	sieve();
	printf("%.6f\n",double(clock()-start)/CLOCKS_PER_SEC);
	return 0;
}
