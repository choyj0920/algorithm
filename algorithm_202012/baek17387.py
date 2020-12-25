# baek17387 선분교차2
import sys
input=sys.stdin.readline

sys.setrecursionlimit(10**9)

d1=list(map(int,input().split()))
d2=list(map(int,input().split()))

def ccw(x1,y1,x2,y2,x3,y3):         # 외적 삼각형 넓이
    temp =x1*y2+x2*y3+x3*y1 +(-y1*x2 - y2*x3-y3*x1)

    if temp<0:      # 시계
        return -1
    elif temp==0:   # 일직선
        return 0 
    else:           # 반시계
        return 1


a=[d1[0],d1[1]]
b=[d1[2],d1[3]]
c=[d2[0],d2[1]]
d=[d2[2],d2[3]]

abc=ccw(*a,*b,*c)
abd=ccw(*a,*b,*d)
cda=ccw(*c,*d,*a)
cdb=ccw(*c,*d,*b)

if abc*abd ==0 and cda*cdb == 0:
    if a>b: a,b=b,a
    if c>d: c,d=d,c
    if a<=d and c<=b:
        print(1)
    else:
        print(0)

elif abc*abd <=0 and cda*cdb <= 0:
    print(1)
else:
    print(0)
    


        