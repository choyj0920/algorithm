# baek13458 시험 감독
import sys
import math
n=int(input())
arr=list(map(int,input().split()))
b,c=map(int,input().split())
ans=0
for i in arr:
    ans+= 1
    if i-b>0:
        ans+=math.ceil((i-b)/c)

print(ans)