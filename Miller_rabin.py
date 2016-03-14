#SPOJ - http://spoj.com/problems/PON/
import random

def exp(a,p,m):
	if (p==0):
		return 1
	elif (p%2==1):
		return (a*exp(a,p-1,m))%m
	x=exp(a,p/2,m)
	return (x*x)%m

def miller_rabin(p):

	if (p==2 or p==3):return 1
	if (p%2==0):return 0
	if (p<3):return 0

	for i in range(10):
		a = random.randrange(2,p-2)
		s=p-1
		while(s%2==0):s/=2
		mod = exp(a,s,p)
		if (mod==1 or mod==p-1):
			continue
		flag=0
		while(s!=(p-1)):
			mod = exp(a,s,p)
			if (mod==(p-1)):
				flag=1
				break
			s*=2
		if (flag==0):
			return 0
	return 1

t=input()

for i in range(t):
	p=input()
	if (miller_rabin(p)==1):
		print('YES')
	else:
		print('NO')
