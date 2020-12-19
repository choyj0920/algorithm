# baek14002 가장 긴 증가하는 부분수열 4

import sys
input =sys.stdin.readline
  

def _print(idx):                    #출력 함수 -dp를 이용해 시작점으로 돌아가며 출력
    if idx== dp[idx]:
        print(arr[idx],end=' ')
        return
    _print(dp[idx])
    print(arr[idx],end=' ')

dp= [0 for _ in range(1010)]        # dp[x] x앞의 인덱스 저장
len= [0 for _ in range(1010)]       # len[x] X까지의 배열길이
n=int(input())

arr = [int(x) for x in input().split()]
MAX=0
for i in range(n):
    dp[i]=i
    len[i]=1
    for j in range(i):
        if arr[j]<arr[i]:           # j가 i보다 작으면
            if len[i]<len[j]+1 :    # 또한 현재 i의 길이보다 j를 포함하는 i 의 길이가 더 길면
                len[i]=len[j]+1     # len ,dp 설정
                dp[i]=j
    if len[i] > len[MAX]: MAX=i     # 최대 길이 저장

print(len[MAX])
_print(MAX)
