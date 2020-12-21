# baek11725 트리의 부모 찾기

import sys
input=sys.stdin.readline
n = int(input())

edges=[[] for _ in range(n+1)]
visited=[False for _ in range(n+1)]
parent=[0 for _ in range(n+1)]

for i in range(n-1):
    a,b=map(int,input().split())
    edges[a].append(b)
    edges[b].append(a)

que =[1]
visited[1]=True
while que:
    x = que.pop(0)
    
    for negihbors in edges[x]:
        if visited[negihbors] == False:
            que.append(negihbors)
            visited[negihbors]=[True]
            parent[negihbors]=x

for _ in range(2,n+1):
    print(parent[_])

        










