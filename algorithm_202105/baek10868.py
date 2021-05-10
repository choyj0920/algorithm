# baek10868 0 = not cute / 1 = cute
import sys
input=sys.stdin.readline
n=int(input())
ans=0
for _ in range(n):
    if int(input()) ==1:
        ans+=1
    else:
        ans-=1
print("Junhee is cute!" if ans>0 else "Junhee is not cute!")