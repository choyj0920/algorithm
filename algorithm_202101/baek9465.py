# baek9465 스티커

import sys
input=sys.stdin.readline
arr=[]
dp=[]

T=int(input())
while T:
    n= int(input())
    arr=[]
    for i in range(2):
        arr.append(list(map(int,input().split())))
    dp=[[0]*n for _ in range(3)]

    dp[0][0]=0
    dp[1][0]=arr[0][0]
    dp[2][0]=arr[1][0]

    for i in range(1,n):
        dp[0][i]=max(dp[1][i-1],dp[2][i-1])
        dp[1][i]=arr[0][i]+max(dp[0][i-1],dp[2][i-1])
        dp[2][i]=arr[1][i]+max(dp[0][i-1],dp[1][i-1])

    print(max(dp[1][n-1],dp[2][n-1]))



    T-=1




