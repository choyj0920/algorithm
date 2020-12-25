# baek1949 우수마을
import sys
input=sys.stdin.readline

sys.setrecursionlimit(10**9)

# input
n= int(input())
edges=[[] for _ in range(n)]
visited=[False for _ in range(n)]
weight=[_ for _ in list(map(int,input().split()))]
dp=[[0,0,0] for _ in range(n)]    # dp[i][0] i노드가 포함 dp[i][1] i노드가 미포함
for _ in range(n-1):
    a,b=map(int,input().split())
    edges[a-1].append(b-1)
    edges[b-1].append(a-1)
# input

# dfs
def dfs(node):
    visited[node]=True          # 방문 체크
    dp[node][0] = weight[node]  # 현재 노드 포함(우수 마을 지정)
    dp[node][1] = 0             # 현재 노드 포함x
    
    for i in edges[node]:
        if not visited[i]:
            dfs(i)
            dp[node][0] += max(dp[i][1],dp[i][2]) # 현재 노드 포함
            dp[node][1] += max(dp[i][1],dp[i][0])



dfs(0) 
print(max(dp[0][0],dp[0][1]))

        
    





