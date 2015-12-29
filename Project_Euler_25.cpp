#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000
#define M 10000000000
#define MAX 1000000
#define fori(l,r,x) for (int i=l;i<=r;i+=x)
#define forj(l,r,x) for (int j=l;j<=r;j+=x)
using namespace std;

//Could have been done much easily using other languages or using custom libraries

char z[1101],x[1101],y[1101];

int add(char x[],char y[]){
	int c=0;
	int i=1100;
	while(i>=0){
		int n = x[i]+y[i]-96+c;
		if(n>9){z[i] = n%10+48;c=1;}
		else{z[i]=n+48;c=0;}
		i--;
	}
	return 0;
}

int len(char x[]){
	int i=0;
	while(i<=1100){
		if (x[i]=='0') i++;
		else break;
	}
	return 1101-i;
}

int input(char in[]){
	char t[1001];
	scanf("%s",t);
	int l = strlen(t);
	int i=l-1;
	int j=1100;
	while(i>=0) in[j--] = t[i--];
	while(j>=0) in[j--] ='0';
	return 0;
}

int set0(char x[]){
	fori(0,1100,1) x[i]='0';
	return 0;
}

int main(){
	clock_t tStart = clock();
	set0(x);
	set0(y);
	x[1100]='1';
	y[1100]='1';
	int i=2;
	while(1){
		set0(z);
		if (len(y)==1000) break;
		add(x,y);
		strcpy(x,y);
		strcpy(y,z);
		i++;
	}
	cout << i << endl;
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}

/*OUTPUT
4782
Time taken: 0.09s
*/
