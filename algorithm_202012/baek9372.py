# baek9372 상근이의 여행
from collections import deque
import sys
input=sys.stdin.readline

T= int(input())

def bfs(x):
    q=deque()
    q.append(x)
    visited[x]=True
    cnt=0
    while q:
        x=q.popleft()
        for nx in edges[x]:
            if visited[nx] ==0:
                visited[nx]=1
                cnt += 1
                q.append(nx)
    
    return cnt
            


while T>0:
    n,m=map(int,input().split())
    visited=[False for _ in range(n)]
    edges=[[] for _ in range(n)]
    for _ in range(m):
        a,b=map(int,input().split())
        edges[a-1].append(b-1)
        edges[b-1].append(a-1)
    
    ans=0
    for i in range(n):
        if not visited[i]:
            ans += bfs(i)
    print(ans)


    T-=1