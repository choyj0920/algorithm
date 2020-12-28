# baek1766 문제집
import sys
from queue import PriorityQueue

input= sys.stdin.readline

n,m = map(int, input().split())
edges=[[]for _ in range(n+1)]
inDegree=[0 for _ in range(n+1)]
for _ in range(m):
    a,b=map(int, input().split())
    edges[a].append(b)
    inDegree[b] +=1

que=PriorityQueue()

for i in range(1,n+1):
    if inDegree[i] ==0:
        que.put(i)

while que.qsize():
    x=que.get()
    print(x,end=' ')
    for next in edges[x]:
        inDegree[next] -=1
        if inDegree[next]==0:
            que.put(next)
    

