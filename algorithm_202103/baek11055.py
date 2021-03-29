# baek11055 가장 큰 증가 부분 수열
import sys
input=sys.stdin.readline
n=int(input())
arr=list(map(int,input().split()))
dp=[0]*n
for i in range(n):
    dp[i]=arr[i] 
    for j in range(0,i):
        if(arr[j]<arr[i]):
            dp[i]=max(dp[i],dp[j]+arr[i])

print(max(dp))

    