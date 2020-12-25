# baek2166 다각형의 면적
import sys
input=sys.stdin.readline

sys.setrecursionlimit(10**9)

# input
n= int(input())

def ccw(x1,y1,x2,y2,x3,y3):         # 외적 삼각형 넓이
    return (x1*y2+x2*y3+x3*y1 +(-y1*x2 - y2*x3-y3*x1))/2
arr=[]
for _ in range(n):
    arr.append(list(map(int,input().split())))

ans=0
for i in range(1,n):
    ans += ccw(*arr[0],*arr[i-1],*arr[i])
print(abs(ans))