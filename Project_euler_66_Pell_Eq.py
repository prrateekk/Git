
from __future__ import print_function
import math
l=[]

def func(x):
	r=math.sqrt(x)
	s=int(r)
	l.append(s)
	a=s
	b=x-s*s
	while(1):
		res = int((r+a)/b)	#push res
		l.append(res)
		a=res*b-a
		b=(x-a*a)/b
		if (a==s and b==(x-s*s)):break
	
	n=len(l)
	if (n%2==0):
		for i in range(1,n):l.append(l[i])
	n=len(l)
	n-=1
	i=n-1
	num=1
	den=0
	while(i>=0):
		t=num
		num=l[i]*num+den
		den=t
		i-=1
	return num
		
		
i=1
m=0
v=0
while(i<=1000):
	l=[]
	x=int(math.sqrt(i))
	if (x*x!=i):
		t=func(i)
		if t>m:
			m=t
			v=i
	i+=1
print(v)
