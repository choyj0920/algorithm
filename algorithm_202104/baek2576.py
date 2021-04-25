# baek2576 홀수
import sys
input=sys.stdin.readline
minvalue=100
ans=0
for i in range(7):
    temp=int(input())
    if temp%2!=0:
        minvalue=min(minvalue,temp)
        ans+=temp
if minvalue==100:
    print(-1)
else:
    print(ans)
    print(minvalue)
