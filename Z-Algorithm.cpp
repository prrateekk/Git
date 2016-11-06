#include <bits/stdc++.h>
#define M 1000000007
#define MAX 600001
using namespace std;

int z[MAX];

int ZAlgorithm(string s,int sz){
	int l = 0,r = 0;
	for (int i=1;i<sz;i++){
		if (i>r){
			l = r = i;
			int j = 0;
			while(r<sz && s[r]==s[j]){
				r++;
				j++;
			}
			z[i] = j;
			r--;
		}
		else{
			int ibar = i-l;
			if (ibar+z[ibar]<=r-l) z[i] = z[ibar];
			else if (ibar+z[ibar]>r-l+1) z[i] = r-i+1;
			else{
				l = i;
				r++;
				int j = r-l;
				while(r<sz && s[r]==s[j]){
					j++;
					r++;
				}
				z[i] = j;
				r--;
			}
		}
	}
	return 0;
}

int main(){

	return 0;
}
