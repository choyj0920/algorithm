# baek2170 선긋기
import sys
input=sys.stdin.readline
n = int(input())
lines=[tuple(map(int,input().split())) for _ in range(n)]

lines.sort()
ans = 0
bS = bE = 0
for s, e in lines:
    if not ans: # 0이면- 처음 값 초기화
        ans = abs(e - s)
        bS = s
        bE = e
        continue
 
    if bS <= s and bE >= e: # 포함 될 때
        continue
    
    ans += abs(e - s)
 
    if bE > s: 
        ans -= abs(bE - s)
    
    bS = s
    bE = e
 
print(ans)