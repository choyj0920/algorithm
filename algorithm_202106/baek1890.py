# baek1890 점프
import sys
input=sys.stdin.readline
n=int(input())
arr=[list(map(int,input().split())) for _ in range(n)]
dp=[[0]*n for _ in range(n)]
dp[0][0]=1
for i in range(n):
    for j in range(n):
        if i==n-1 and j==n-1:
            break
        jump =arr[i][j]
        if i+jump<n:
            dp[i+jump][j] += dp[i][j]

        if j+jump<n:
            dp[i][j+jump] += dp[i][j]

print(dp[n-1][n-1])