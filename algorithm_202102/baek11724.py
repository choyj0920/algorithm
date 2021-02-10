# baek11724 연결 요소의 개수
from sys import stdin
from collections import deque

input = stdin.readline
n,m=map(int,input().split())

visited=[False]*(n+1)
edges=[[] for _ in range(n+1)]

for _ in range(m):
    a,b=map(int,input().split())
    edges[a].append(b)
    edges[b].append(a)

def bfs(node):
    que=deque([node])
    visited[node]=True
    while que:
        cur=que.pop()
        for next in edges[cur]:
            if not visited[next]:
                visited[next]=True
                que.append(next)
ans=0
for _ in range(1,n+1):
    if not visited[_]:
        ans+=1
        bfs(_)
print(ans)
                
