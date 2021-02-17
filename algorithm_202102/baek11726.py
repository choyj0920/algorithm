# baek11726 2xn타일
import sys
n=int(input())
dp=[0]*(n+3)
dp[0]=1
for i in range(0,n+1):
    dp[i+1]=(dp[i+1]+dp[i])%10007
    dp[i+2]=(dp[i+2]+dp[i])%10007

print(dp[n])
