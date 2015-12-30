#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000
#define M 10000000000
#define MAX 10000000
#define fori(l,r,x) for (int i=l;i<=r;i+=x)
#define forj(l,r,x) for (int j=l;j<=r;j+=x)
using namespace std;

int p[MAX+1],sum=0,c=0;

int len(ll int x){
	int l=0;
	while(x){
		l++;
		x/=10;
	}
	return l;
}

int isprime(ll int x){
	ll int sq = sqrt(x);
	fori(2,sq,1) if (x%i==0) return 0;
	return 1;
}

int check(ll int x){
	if (x==0||x==3||x==7||x==9||x==2||x==5) return 0;
	ll int temp = x;
	int l = len(x);
	int i=0;
	while(i<l){
		if (x<=MAX&&p[x]==1) return 0;
		if (x>MAX&&isprime(x)==0) return 0;
		x/=10;
		i++;
	}
	x=temp;
	ll int pw = pow(10,l-1);
	i=0;
	while(i<l){
		if (x<=MAX&&p[x]==1) return 0;
		if (x>MAX&&isprime(x)==0) return 0;
		x=x%pw;
		pw/=10;
		i++;
	}
	c++;
	cout << temp << endl;
	sum+=temp;
	return 0;
}

int func(int i,ll int x){
	check(x);
	if (i==6) return 0;
	if (i!=0)
	func(i+1,x*10+1);
	if (i==0)
	func(i+1,x*10+2);
	if (i==0)
	func(i+1,x*10+5);
	func(i+1,x*10+3);
	func(i+1,x*10+7);
	if (i!=0)
	func(i+1,x*10+9);
	return 0;
}

int init(){
	p[0]=p[1]=1;
	fori(2,MAX,1) if (!(p[i])) forj(i<<1,MAX,i) p[j]=1;
	func(0,0);
	cout <<endl<< c<<endl<<sum << endl;
	return 0;
}

int main(){
	clock_t tStart = clock();
	init();
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
