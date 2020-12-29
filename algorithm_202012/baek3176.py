# baek3176 도로 네트워크

import sys
from math import log2
from collections import deque
input=sys.stdin.readline

n=int(input())
logN=int(log2(n)+1)
tree =[[] for _ in range(n+1)] # 각노드의 연결 노드
for _ in range(n-1):
    a,b,c=map(int,input().split())
    tree[a].append([b,c])
    tree[b].append([a,c])

p_list=[[0,0] for _ in range(n+1)]  # 부모노드 저장
depth=[0 for _ in range(n+1)]   # 부모노드 개수

visited=[False for _ in range(n+1)] # dfs 방문

q=deque()
q.append(1) # 루트
visited[1] =True
while q:
    p=q.popleft()
    for i,d in tree[p]:
        if not visited[i]:
            q.append(i)
            p_list[i][0]=p
            p_list[i][1]=d
            visited[i] = True
            depth[i]=depth[p]+1

# 2^k 번쨰 부모노드 저장
# log2 1000000 
dp=[[[0,0,0] for _ in range(logN)] for i in range(n+1)] 
# dp[a][b] =[a의 2^b 번째 부모노드,a부터 그 부모노드까지의 최소도로,최장 도로]

for i in range(n+1):    # 
    dp[i][0][0]=p_list[i][0]
    dp[i][0][1]=p_list[i][1]
    dp[i][0][2]=p_list[i][1]


for j in range(1,logN): # 희소 테이블 설정
    for i in range(1,n+1):
        dp[i][j][0]=dp[dp[i][j-1][0]][j-1][0]
        dp[i][j][1]=min(dp[i][j-1][1],dp[dp[i][j-1][0]][j-1][1])
        dp[i][j][2]=max(dp[i][j-1][2],dp[dp[i][j-1][0]][j-1][2])

m= int(input())
for _ in range(m):
    a,b=map(int,input().split())
    if depth[a]>depth[b]:
        a,b=b,a
    # 둘의 레벨 차이
    dif =depth[b]-depth[a]
    shortest = 1000000
    longest = 0
    for i in range(logN):
        if dif&(1<<i):
            shortest=min(shortest,dp[b][i][1])
            longest=max(longest,dp[b][i][2])
            b=dp[b][i][0]
            
    if a==b:    # 같으면 출력
        print(shortest,longest)
        continue
    
    for i in range(logN-1,-1,-1): # 루트 부터 내려가다가 처음달라지는 순간 노드의
        if dp[a][i][0] != dp[b][i][0] and dp[a][i][0] != 0 and dp[b][i][0] !=0:
            shortest=min(shortest,dp[a][i][1],dp[b][i][1])
            longest=max(longest,dp[a][i][2],dp[b][i][2])
            a=dp[a][i][0]
            b=dp[b][i][0]
            
    # 경로에 최소 공통조상밑의 경로까지 포함
    shortest=min(shortest,dp[a][0][1],dp[b][0][1])
    longest=max(longest,dp[a][0][2],dp[b][0][2])


    print(shortest,longest)# 결과
    
    







