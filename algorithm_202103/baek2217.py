# baek2217 로프
import sys
input=sys.stdin.readline
arr=[]
n=int(input())
for i in range(n):
    arr.append(int(input()))

arr=sorted(arr)
ans=0
for i in range(len(arr)):
    ans=max(ans,arr[i]* (n-i))
print(ans)