# baek14003 가장 긴 증가하는 부분수열 5

import sys
input =sys.stdin.readline
  
# 입력
n=int(input())
arr = [int(x) for x in input().split()]

dp= [0 for _ in range(1000005)]        # dp[x] x앞의 인덱스 저장
ans=[[0,0] for _ in range(1000005)]    # 값들 저장


def _lower_bound(start, end ,target): # 이진탐색 함수
    while start<end:
        mid= (start+end)//2
        if dp[mid]<target:
            start= mid+1
        else:
            end=mid
    return end
        

cnt=0 #dp 배열 개수-1
dp[0]=arr[0]
ans[0]=[0,arr[0]]
for i in range(1,n):
    if (dp[cnt]< arr[i]): #arr[i] 가 최대값보다 크면
        cnt+=1
        dp[cnt] =arr[i]
        
        # arr[i] 까지 lis값, arr[i] 값 저장
        ans[i]=[cnt,arr[i]]
    else:                   # arr[i] 가 최대값보다 작으면 중간에 삽입
        pos = _lower_bound(0,cnt,arr[i])
        dp[pos] =arr[i]
        
        # arr[i] 까지 lis값, arr[i] 값 저장
        ans[i]=[pos,arr[i]]
    
print(cnt+1)
t=cnt
pList=[]

for i in range(n-1,-1,-1):
    if(ans[i][0] == t):
        pList.append(ans[i][1])
        t-=1

for i in range(len(pList)-1,-1,-1):
    print(pList[i],end=' ')
