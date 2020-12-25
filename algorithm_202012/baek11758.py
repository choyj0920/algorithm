# baek11758 CCW
import sys
input=sys.stdin.readline

sys.setrecursionlimit(10**9)


def ccw(x1,y1,x2,y2,x3,y3):         # 외적 삼각형 넓이
    return (x1*y2+x2*y3+x3*y1 +(-y1*x2 - y2*x3-y3*x1))/2
# input 
arr=[]
for _ in range(3):
    arr.append(list(map(int,input().split())))

check= ccw(*arr[0],*arr[1],*arr[2])
if check>0:
    print(1)
elif check<0:
    print(-1)
else:
    print(0)

