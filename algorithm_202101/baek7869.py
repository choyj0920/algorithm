# 7869 두 원

import sys
import math
input=sys.stdin.readline

x1,y1,r1,x2,y2,r2=map(float,input().split())

d_2 = ((x1-x2)**2) + ((y1-y2)**2) # 중심 거리 제곱
d=math.sqrt(d_2)
a= r1*r1            # 반지름1 제곱
b= r2*r2            # 반지름2 제곱
if a<b: # a를 큰 값으로
    a,b= b,a
    r1,r2=r2,r1

if d_2 > (r1+r2)**2: # 원이 만나지 않는 경우 
    print(round(0,3))
elif d==0:           # 원의 중심이 일치 하는 경우
    print(round(math.pi*b,3))
elif d_2+b>= a:      #  경우 1 부채꼴 두개 - 삼각형두개 
    cos_halfT1 =  (d_2+a-b)/(2*r1*d)
    cos_halfT2 =  (d_2-a+b)/(2*r2*d)
    t1=(math.acos(cos_halfT1)) * 2
    t2=(math.acos(cos_halfT2)) * 2

    S= (a*(t1-math.sin(t1))+b*(t2-math.sin(t2)))/2
    print(round(S,3))

elif d_2> (r1-r2)**2:   # 경우2 
    cos_halfT1 =  (a+d_2-b)/(2*r1*d)
    cos_halfT2 =  (b+d_2-a)/(2*r2*d)
    half_t1=(math.acos(cos_halfT1)) 
    t1=half_t1*2
    t2=(math.acos(cos_halfT2)) * 2

    S= ((b*t2+a*t1)/2) -(d*r1*math.sin(half_t1))
    print(round(S,3))
else:
    print(round(math.pi*b,3))







