#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000
#define M 10000000000
#define MAX 1000000
#define fori(l,r,x) for (int i=l;i<=r;i+=x)
#define forj(l,r,x) for (int j=l;j<=r;j+=x)
using namespace std;

//Brute Force

ll int f[10];
int mark[10];

int fac(int x){
	int p=1;
	fori(2,x,1) p*=i;
	return p;
}

int print(int mark[]){
	fori(0,9,1) printf("%d ",mark[i]);
	cout << endl;
	return 0;
}

int check(int mark[]){
	int mark1[10];
	fori(0,9,1) mark1[i]=mark[i];
	ll int sum=0;
	fori(0,9,1){
		sum+=(f[i]*mark1[i]);
	}
	ll int temp=sum;
	while(sum){
		mark1[sum%10]--;
		sum/=10;
	}
	int f=0;
	fori(0,9,1){
		if (mark1[i]!=0){
			f=1;
			break;
		}
	}
	if (f==0&&temp!=1&&temp!=2&&temp!=0) cout << temp << endl;
	return 0;
}


int func(int i,int mark[]){
	if (i==10){check(mark);return 0;}
	forj(0,2,1){
		mark[i]=j;
		func(i+1,mark);
	}
	mark[i]=0;
	return 0;
}

int init(){
	f[0]=1;
	fori(1,9,1) f[i]=f[i-1]*i;
	return 0;
}

int main(){
	init();
	func(0,mark);
	return 0;
}
