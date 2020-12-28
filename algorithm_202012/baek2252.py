# baek2252 줄 세우기
import sys
input= sys.stdin.readline

n,m = map(int, input().split())
edges=[[]for _ in range(n+1)]
inDegree=[0 for _ in range(n+1)]
for _ in range(m):
    a,b=map(int, input().split())
    edges[a].append(b)
    inDegree[b] +=1
que=[]

for i in range(1,n+1):
    if inDegree[i] ==0:
        que.append(i)

while len(que)>0:
    x=que.pop(0)
    print(x,end=' ')
    for next in edges[x]:
        inDegree[next] -=1
        if inDegree[next]==0:
            que.append(next)
    

