#Project_Euler_100 doubt Wrong Answer

from math import sqrt

def solve_quad(a,b,c,t):
	d=b*b-4*a*c
	if d<0:return -1
	d=sqrt(d)
	r1 = (-b+d)/(2*a)
	r2 = (-b-d)/(2*a)
	if (r1>0 and r1==long(r1) and r1<t):return long(r1)
	if (r2>0 and r2==long(r2) and r2<t):return long(r2)
	return -1

t=float(1000000002604)
x=float(707106783028) #getting x as answer
s=((t*(t-1))/(x*(x-1)))
print(s)

MAX=1000000000000
t=MAX
while(1):
	y=solve_quad(2,2-4*t,t*t-t,t)
	if y!=-1:
		print(t)
		print(max(y,t-y))
		break
	t+=1

