# baek15681 트리와 쿼리

import sys
input=sys.stdin.readline

sys.setrecursionlimit(10**9)
n,r,q=map(int,input().split())
r -= 1
edges=[[] for _ in range(n)]
parent=[ 0 for _ in range(n)]           # 부모노드
visited= [False for _ in range(n)]
cnt=[0 for _ in range(n)]

# dfs
def dfs(node):
    cnt[node]=1
    for i in edges[node]:
        if not visited[i]:
            visited[i]=True # 값 설정
            parent[i]=node
            cnt[node] +=dfs(i)
    return cnt[node]

for _ in range(n-1):
    u,v =map(int,input().split())       # 간선 입력
    edges[u-1].append(v-1)
    edges[v-1].append(u-1)

visited[r]=True
dfs(r)
for _ in range(q):
    print(cnt[int(input())-1])
    
    
    


