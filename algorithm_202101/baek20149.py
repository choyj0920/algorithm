# baek20149 선분교차3
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

if abc*abd ==0 and cda*cdb == 0:        # 선분이 평행 할 때
    if a>b: a,b=b,a                     
    if c>d: c,d=d,c
    if a==d and c<b:
        print(1)
        print(*a)
    elif a<d and c==b:
        print(1)
        print(*c)
    elif a<=d and c<=b:
        print(1)
    else:
        print(0)

elif abc*abd <=0 and cda*cdb <= 0:  # 선분이 평행하지 않을 때
    _A=b[1]-a[1]            # L1 _Ax + _By = _E
    _B=a[0]-b[0]
    _E=(_A*a[0])+(_B*a[1])
    _C=d[1]-c[1]            # L2 _Cx + _Dy = _F
    _D=c[0]-d[0]
    _F=(_C*c[0])+(_D*c[1])
    _DE=(_A*_D)-(_B*_C)
    print(1)
    if _DE != 0:
        print(((_E*_D)-(_B*_F))/_DE, ((_A*_F)-(_E*_C))/_DE,end=' ')
else:
    print(0)
    


        