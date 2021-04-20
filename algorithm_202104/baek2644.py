# baek2644 촌수계산
import sys
input=sys.stdin.readline
n=int(input())
edge=[[] for _ in range(n+1)]
visited=[False]*(n+1)
a,b=map(int,input().split())
m=int(input())
for i in range(m):
    x,y=map(int,input().split())
    edge[x].append(y)
    edge[y].append(x)
ans=-1
def dfs(node,cnt):
    global ans
    if node == b:
        ans=cnt
        return
    if visited[node]:
        return
    visited[node]=True

    for i in edge[node]:
        if not visited[i]:
            dfs(i,cnt+1)

dfs(a,0)
print(ans)