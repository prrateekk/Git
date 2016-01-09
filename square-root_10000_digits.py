#square-root upto 10000 decimal places in 0.1s

from __future__ import print_function
import math
import time
st=[0 for i in range(20000)]

def count(x):
	sq = int(math.sqrt(x))
	num=1
	den=-1*sq
	c=0
	res=sq
	while(1):
		temp=den
		den=(x-den*den)/num
		num=-1*temp
		res=(num+sq)/den
		st[c]=res
		c+=1
		num-=(res*den)
		if(den==1):break
		num,den=den,num
	return c

def sqroot(nb):
	x=count(nb)
	i=x
	while(i<20000):
		for j in range(x):
			st[i]=st[j]
			i+=1
	num=st[i-1]
	den=1
	i-=2
	while(i>=0):
		t=num
		num=num*st[i]+den
		den=t
		i-=1
	i=0
	print(int(math.sqrt(nb)),end=".")
	num,den=den,num

	while(i<10000):
		num*=10
		print(int(num/den),end="")
		num=num%den
		i+=1
	return sum


t0=time.clock()
sqroot(2)
