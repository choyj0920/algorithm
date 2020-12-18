# baek12852 1로 만들기2

import sys

#input
input=sys.stdin.readline

dp= [[0,0] for _ in range(1000003) ]

n=int(input())

dp[1]=[0,0]
for i in range(2,n+1):
    dp[i]= [dp[i-1][0]+1,dp[i-1][1] | 1<< (2*dp[i-1][0])]
    if i % 2==0 and dp[i][0]> dp[i//2][0]+1:
        dp[i]=[dp[i//2][0]+1 ,dp[i//2][1] | 2<<(2*dp[i//2][0])]
    if i % 3==0 and dp[i][0]> dp[i//3][0]+1:
        dp[i]=[dp[i//3][0]+1 ,dp[i//3][1] | 3<<(2*dp[i//3][0])]

answer=dp[n][0]
print(dp[n][0])
bit=dp[n][1]
temp=n

for i in range(answer,0,-1):
    print(int(temp),end=" ")
    x = (dp[n][1] & (3<<(2*(i-1)))) >>   (2 * (i-1))
    if x==1:
        temp -=1
    elif x==2:
        temp /=2
    else:
        temp /=3
print(int(temp))
