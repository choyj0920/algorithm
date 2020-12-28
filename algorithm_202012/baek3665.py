# baek3665 최종순위
import sys
from collections import deque
input= sys.stdin.readline

def TopologicalSort():
    global isImpossible,isAmbiguous

    for _ in range(n):
        if not dq:
            isImpossible = True
            return
        if len(dq)>1:
            isAmbiguous=True
            return

        target=dq.popleft()
        answer.append(target)

        for x in edges[target]:
            inDegree[x]-=1
            
            if not inDegree[x]:
                dq.append(x)


testCase=int(input())
while testCase>0:
    n=int(input())
    
    isImpossible=False
    isAmbiguous=False
    answer=[]
    inDegree=[0]*(n+1)
    edges=[[] for _ in range(n+1)]

    lastYear=list(map(int,input().split()))

    for i in range(n):
        for j in range(i+1,n):
            inDegree[lastYear[j]]+=1
            edges[lastYear[i]].append(lastYear[j])
    m= int(input())

    for _ in range(m):      # 순위 변경
        a,b=map(int,input().split())
        
        isFound=False      # 순위를 변경하는데, 현재 a가 위에있는지

        for i in edges[a]:
            if i==b:         # a가 선 순위 였다면...
                isFound=True
                inDegree[a]+=1
                inDegree[b]-=1
                edges[a].remove(b)
                edges[b].append(a)

        if not isFound:     # b가 선 순위 였다면
            inDegree[a] -= 1
            inDegree[b] += 1
            edges[b].remove(a)
            edges[a].append(b)

    dq=deque()
    for i in range(1,n+1):
        if not inDegree[i]:
            dq.append(i)
    
    TopologicalSort()


    if isImpossible:
        print("IMPOSSIBLE")
    elif isAmbiguous:
        print("?")
    else:
        print(*answer)
                




    testCase-=1
