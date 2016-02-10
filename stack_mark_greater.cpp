#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

int mark_right[MAX],mark_left[MAX],a[MAX];

//marks greater index both on left and right side

int mark_greater(int ar[]){
	set(mark_right,-1);
	set(mark_left,-1);
	int s[n][2],top=0;
	s[0][0] = ar[0];
	s[0][1] = 0;
	int i=1;
	while(i<n){
		if (top==-1||s[top][0]>=ar[i]){
			s[++top][0] = ar[i];
			s[top][1] = i;
			i++;
		}
		else{
			mark_right[s[top][1]] = i;
			top--;
		}
	}
	fori(0,n-1,1) cout << mark_right[i]  << " " ;
	cout << endl;
	top=0;
	s[0][0] = ar[n-1];
	s[0][1] = n-1;
	i=n-2;
	while(i>=0){
		if (top==-1||s[top][0]>ar[i]){
			s[++top][0] = ar[i];
			s[top][1] = i;
			i--;
		}
		else{
			mark_left[s[top][1]] = i;
			top--;
		}
	}
	fori(0,n-1,1) cout << mark_left[i]  << " " ;
	cout << endl;
	return 0;
}

int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  mark_greater(a);
  return 0;
}
