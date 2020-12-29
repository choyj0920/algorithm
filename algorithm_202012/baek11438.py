# baek11438 LCA2

import sys
from math import log2
from collections import deque
input=sys.stdin.readline

n=int(input())
logN=int(log2(n)+1)
tree =[[] for _ in range(n+1)] # 각노드의 연결 노드
for _ in range(n-1):
    a,b=map(int,input().split())
    tree[a].append(b)
    tree[b].append(a)

p_list=[0 for _ in range(n+1)]  # 부모노드 저장
depth=[0 for _ in range(n+1)]   # 부모노드 개수

visited=[False for _ in range(n+1)] # dfs 방문

q=deque()
q.append(1) # 루트
while q:
    p=q.popleft()
    visited[p] =True
    for i in tree[p]:
        if not visited[i]:
            q.append(i)
            p_list[i]=p
            depth[i]=depth[p]+1

# 2^k 번쨰 부모노드 저장
# log2 1000000 
dp=[[0 for _ in range(logN)] for i in range(n+1)] # dp[a][b] a의 2^b 번째 부모노드

for i in range(n+1):
    dp[i][0]=p_list[i]

for j in range(1,logN): # 희소 테이블 설정
    for i in range(1,n+1):
        dp[i][j]=dp[dp[i][j-1]][j-1]

m= int(input())
for _ in range(m):
    a,b=map(int,input().split())
    if depth[a]>depth[b]:
        a,b=b,a
    # 둘의 레벨 차이
    dif =depth[b]-depth[a]
    for i in range(logN):
        if dif&(1<<i):
            b=dp[b][i]
            
    if a==b:    # 같으면 출력
        print(a)
        continue
    for i in range(logN-1,-1,-1): # 루트 부터 내려가다가 처음달라지는 순간 노드의
        if dp[a][i] != dp[b][i]:
            a=dp[a][i]
            b=dp[b][i]
    print(dp[b][0])     # 바로 부모노드가 정답
    
    







