# baek14002 가장 긴 증가하는 부분수열 4

import sys
input =sys.stdin.readline
  

def _print(idx):
    if idx== dp[idx]:
        print(arr[idx],end=' ')
        return
    _print(dp[idx])
    print(arr[idx],end=' ')

dp= [0 for _ in range(1010)]
len= [0 for _ in range(1010)]
n=int(input())

arr = [int(x) for x in input().split()]
MAX=0
for i in range(n):
    dp[i]=i
    len[i]=1
    for j in range(i):
        if arr[j]<arr[i]:
            if len[i]<len[j]+1 :
                len[i]=len[j]+1
                dp[i]=j
    if len[i] > len[MAX]: MAX=i

print(len[MAX])
_print(MAX)
