# baek11722 가장 긴 감소하는 부분 수열
import sys  
input =sys.stdin.readline
n=int(input())
arr=list(map(int,input().split()))
dp=[1]*n
for i in range(n):
    for j in range(i):
        if arr[j]> arr[i]:
            dp[i]=max(dp[j]+1,dp[i])
print(max(dp))