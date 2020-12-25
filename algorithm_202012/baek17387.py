# baek17386 CCW
import sys
input=sys.stdin.readline

sys.setrecursionlimit(10**9)

d1=list(map(int,input().split()))
d2=list(map(int,input().split()))

def ccw(x1,y1,x2,y2,x3,y3):         # 외적 삼각형 넓이
    if x1*y2+x2*y3+x3*y1 +(-y1*x2 - y2*x3-y3*x1)<0:
        return 1
    else: 
        return -1

a=[d1[0],d1[1]]
b=[d1[2],d1[3]]
c=[d2[0],d2[1]]
d=[d2[2],d2[3]]

abc=ccw(*a,*b,*c)
abd=ccw(*a,*b,*d)
cda=ccw(*c,*d,*a)
cdb=ccw(*c,*d,*b)

if abc*abd <=0 and cda*cdb <=0:
    print(1)
else:
    print(0)


        