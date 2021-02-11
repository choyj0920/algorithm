# baek1024 수열의 합
import sys
input=sys.stdin.readline

n,l=map(int,input().split())

i=l
cnt=0
for _ in range(1,i):
    cnt+=_
while i<=100:
    temp= n-cnt
    if temp%i== 0:
        temp //=i
        break
    else:
        cnt+=i
        i+=1

if i>100 or temp < 0: # 길이가 100을 넘어 갈 때, 음수부분 제거
    print(-1)
else:
    print(*range(temp,temp+i))
    