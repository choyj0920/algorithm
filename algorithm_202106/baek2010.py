# baek2010 플러그
import sys
input =sys.stdin.readline
n=int(input())
arr=[]
for i in range(n):
    arr.append(int(input()))
arr.sort()
ans=1
for i in arr:
    if i <=1:
        break
    ans+=(i-1)
print(ans)

