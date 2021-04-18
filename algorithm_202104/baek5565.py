# baek5565  영수증
import sys
input=sys.stdin.readline
ans=int(input())
for i in range(9):
    ans-=int(input())

print(ans)