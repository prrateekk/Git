#include <bits/stdc++.h>
#define ll long long
#define INF 100000000
#define M 1000000
#define MAX 65536
#define X 6
#define set(x,y) memset(x,y,sizeof(x))
#define fori(l,r,x) for (int i=l;i<=r;i+=x)
#define forj(l,r,x) for (int j=l;j<=r;j+=x)
using namespace std;

char st[100],p;

int func(int x){
	if (x==0) return 0;
	if (x==4){
		st[p++]='I';
		st[p++]='V';
		return 0;
	}
	if (x==9){
		st[p++]='I';
		st[p++]='X';
		return 0;
	}
	if (x>=40&&x<50){
		st[p++]='X';
		st[p++]='L';
		return func(x-40);
	}
	if (x>=90&&x<100){
		st[p++]='X';
		st[p++]='C';
		return func(x-90);
	}
	if (x>=400&&x<500){
		st[p++]='C';
		st[p++]='D';
		return func(x-400);
	}
	if (x>=900&&x<1000){
		st[p++]='C';
		st[p++]='M';
		return func(x-900);
	}
	if (x<5) {st[p++]='I';return func(x-1);}
	if (x<10) {st[p++]='V';return func(x-5);}
	if (x<50) {st[p++]='X';return func(x-10);}
	if (x<100) {st[p++]='L';return func(x-50);}
	if (x<500) {st[p++]='C';return func(x-100);}
	if (x<1000) {st[p++]='D';return func(x-500);}
	st[p++]='M';return func(x-1000);
	return 0;
}

int init(){
	int t=1;
	while(t++){
		int n=t-1;
		p=0;
		func(n);
		fori(0,p-1,1) cout << st[i];
		cout << endl;
		if (t==100) break;
	}
	return 0;
}

int main(){
	//clock_t tStart = clock();
	init();
	//printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
