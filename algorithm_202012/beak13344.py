# baek13344 Chess Tournament
import sys
from collections import deque
input= sys.stdin.readline
sys.setrecursionlimit(10**9)
# union_find 함수 
def getParent(x):
    if parent[x]==x: return x
    parent[x] = getParent(parent[x])
    return parent[x]

def unionParent(a,b):
    a=getParent(a)
    b=getParent(b)
    if a<b: parent[b]=a
    else: parent[a]=b
def checkUnion(a,b):
    if getParent(a)==getParent(b):
        return True
    else: 
        return False

# union_find 함수 



def TopologicalSort():
    global isInconsistent

    for _ in range(n):
        if not dq:
            isInconsistent = True
            return

        target=dq.popleft()
        answer.append(target)

        for x in edges[target]:
            inDegree[x]-=1
            if checkUnion(target,x):
                isInconsistent=True
                return
            
            if not inDegree[x]:
                dq.append(x)

n,m=map(int,input().split())
isInconsistent=False
answer=[]
inDegree=[0]*(n+1)
edges=[[] for _ in range(n)]
parent=[_ for _ in range(n)]

tmp=[]
for _ in range(m):
    a,sign,b=input().split()
    a,b=int(a),int(b)
    if sign=='=':
        unionParent(a,b)
    elif sign=='>':
        tmp.append([a,b])

for _ in range(n):
    parent[_]=getParent(_)
for a,b in tmp:
    a=parent[a]
    b=parent[b]
    edges[a].append(b)
    inDegree[b]+=1


dq=deque()
for i in range(n):
    if not inDegree[i]:
        dq.append(i)
    
TopologicalSort()

if isInconsistent or len(answer) != n:
    print("inconsistent")
else:
    print("consistent")
    
            