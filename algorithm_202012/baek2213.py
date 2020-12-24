# baek2213 트리의 독립집합

import sys
input=sys.stdin.readline

sys.setrecursionlimit(10**9)
n= int(input())
weight=[int(_) for _ in input().split() ]
edges=[[] for _ in range(n)]
visited=[False for _ in range(n)]
dp=[[0,0] for _ in range(n)]    # dp[i][0] i노드가 포함 dp[i][1] i노드가 미포함
for _ in range(n-1):
    a,b=map(int,input().split())
    edges[a-1].append(b-1)
    edges[b-1].append(a-1)

def dfs(node):
    visited[node]=True         # 방문 체크
    dp[node][0] = weight[node]  # 현재 노드 포함
    dp[node][1] = 0             # 현재 노드 포함 x
    for i in edges[node]:
        if not visited[i]:
            dfs(i)
            dp[node][0] += dp[i][1]
            if dp[i][0]< dp[i][1]:
                dp[node][1] += dp[i][1]
            else:
                dp[node][1] += dp[i][0]



trace_result=[]
trace_check=[False for _ in range(n+1)]
def Trace(cur, pre): # 현재노드와 이전노드가 포함되었는 지 안 되었는지 
    trace_check[cur]=True

    if pre ==0: # 이전 노드가 포함되었다면
        for i in edges[cur]: # 현재노드 포함x
            if not trace_check[i]:
                Trace(i,1)
    else :      # 이전 노드가 포함되어 있지 않다면
        if dp[cur][0] > dp[cur][1]:         # 현재 노드를 포함한 부분이 더 크다면
            trace_result.append(cur+1)        # 현재 노드 포함
            for i in edges[cur]:
                if not trace_check[i]:
                    Trace(i,0)
        else :                              # 현재 노드를 포함하지 않은 부분이 더 크다면
            for i in edges[cur]:            
                if not trace_check[i]:
                    Trace(i,1)

dfs(0) 
print(max(dp[0][0],dp[0][1]))
Trace(0,1)
trace_result.sort()
print(*trace_result)

        
    





