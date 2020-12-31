# baek2150 Strongly Connected Component
import sys
from collections import deque
input=sys.stdin.readline
sys.setrecursionlimit(10**9)

v,e =map(int,input().split())
edges=[[] for _ in range(v+1)]
for _ in range(e):
    a,b = map(int, input().split() )
    edges[a].append(b)
    
visited=[0 for _ in range(v+1)]
finished=[False for _ in range(v+1)]

stack=[]
id = 0
SCC=[]
def dfs(node ):
    global id
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
    if parent==visited[node]:
        scc=[]
        while True:
            t=stack.pop()
            scc.append(t)
            finished[t]=True
            if t==node: break
        scc=sorted(scc)
        SCC.append(scc)

    # 부모 출력
    return parent

for i in range(1,v+1):
    if not visited[i]: dfs(i)
SCC=sorted(SCC)
print(len(SCC))
for i in range(len(SCC)):
    print(*SCC[i],end=' -1\n')
    
            
        


        

