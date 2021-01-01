# baek4013 ATM

import sys
from collections import deque
input=sys.stdin.readline
sys.setrecursionlimit(10**9)

n,m=map(int,input().split())
edges=[[] for _ in range(n+1)]
visited=[0 for _ in range(n+1)]
finished=[False for _ in range(n+1)]
SCCnum=[0 for _ in range(n+1)]
money=[0 for _ in range(n+1)]

for _ in range(m):
    a,b=map(int,input().split())
    edges[a].append(b)
for _ in range(1,n+1):
    money[_]=int(input())

start,rescnt=map(int,input().split())
restlist=list(map(int,input().split()))
moneyscc=[0 for _ in range(n+1)]

stack=[]
id = 0
SCCtotal=0
SCC=[]
def dfs(node ):
    global id,SCCtotal
    id += 1
    visited[node]= id  # node 별 dfs 순서 정의를 위해  0이면 아직 미 방문
    stack.append(node) # 스택에 삽입 - 같은 강한결합요소 체크를 위해
    parent =visited[node]
    for next in edges[node]:
        # 아직 방문하지 않았다면, dfs 수행 
        if visited[next] ==0: parent=min(parent, dfs(next))
        # 현재 dfs가 수행중인--> 부모일수도 아니면 형제일수도 
        elif not finished[next]: parent =min(parent,visited[next])
    
    # 부모 노드가 자기 자신인 경우
    if parent==visited[node] and not finished[node]:
        scc=[]
        while True:
            t=stack.pop()
            SCCnum[t]= SCCtotal
            moneyscc[SCCtotal]+=money[t]
            scc.append(t)
            finished[t]=True
            if t==node: break
        SCCtotal+=1
        SCC.append(scc)

    # 부모 출력
    return parent

dfs(start)

dp=[0 for _ in range(n+1)]

dp[SCCtotal-1]=moneyscc[SCCtotal-1]

for i in range(SCCtotal-1,-1,-1):
    for elem in SCC[i]:
        for next in edges[elem]:
            if SCCnum[next] != i:
                dp[SCCnum[next]] = max(dp[SCCnum[next]], dp[i]+ moneyscc[SCCnum[next]])
ans=0
for i in restlist:
    if visited[i]:
        ans=max(ans,dp[SCCnum[i]])   
print(ans)
