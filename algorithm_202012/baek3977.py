# baek3977 축구전술

import sys
from collections import deque
input=sys.stdin.readline
sys.setrecursionlimit(10**9)

id=0
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
    if parent==visited[node]:
        scc=[]
        while True:
            t=stack.pop()
            SCCnum[t]= SCCtotal
            scc.append(t)
            finished[t]=True
            if t==node: break
        SCCtotal+=1
        SCC.append(scc)

    # 부모 출력
    return parent

T = int(input())
while T:
    v,e =map(int,input().split())
    edges=[[] for _ in range(v+1)]
    for _ in range(e):
        a,b = map(int, input().split())
        edges[a].append(b)

    visited=[0 for _ in range(v)]
    finished=[False for _ in range(v)]
    SCCnum=[0 for _ in range(v)]
    inDegree = [0 for _ in range(v)]

    stack=[]
    id = 0
    SCCtotal=0
    SCC=[]

    for i in range(v):
        if not visited[i]: dfs(i)
    
    for i in range(v):  # SCC 끼리 연결되있는게 있으면 +1 해서 나중에 연산제외
        for j in edges[i]:  # i -> j 가 된다면
            if SCCnum[i] != SCCnum[j]:  # 같은 scc로 묶여있지 않다면
                inDegree[SCCnum[j]]+=1
    answer=0
    idx=0
    for i in range(SCCtotal):
        if not inDegree[i]:
            answer+=1
            idx=i
    if answer==1:
        for _ in sorted(SCC[idx]):
            print(_)
    else:
        print("Confused")
    input()
    print()
    T-=1
