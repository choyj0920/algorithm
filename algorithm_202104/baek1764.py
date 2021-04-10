# baek1764 듣보잡
import sys
input=sys.stdin.readline
nosee=dict()
n,m=map(int,input().split())
arr=[]
for _ in range(n):
    temp=input().rstrip()
    nosee[temp]=1
for _ in range(m):
    temp=input().rstrip()
    if temp in nosee:
        arr.append(temp)
print(len(arr))
arr.sort()
for _ in arr:
    print(_)