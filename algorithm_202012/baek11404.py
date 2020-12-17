# 백준 11404 플로이드

import sys
input =sys.stdin.readline
INF= int(1e9)  #무한을 의미하는 값으로 10억을 설정

def floydWarshall():
    # k = 거쳐가는 노드
    for k in range(1,n+1):
        # i= 출발 노드
        for i in range(1,n+1):
            # j = 도착 노드
            for j in range(1,n+1):
                if edges[i][k]+edges[k][j] <edges[i][j]:
                    edges[i][j]= edges[i][k]+edges[k][j] 

# 노드의 개수, 간선의 개수 입력
n= int(input())
m= int(input())
# 경로 배열 
edges=[[INF]*(n+1) for _ in range(n+1)]

for _ in range(m): #같은 노선 다른 경로 존재
    a,b,c=map(int,input().split())
    edges[a][b]=min(edges[a][b],c)
for i in range(1,n+1): # 같은 노드 끼리 0
    edges[i][i]=0

floydWarshall() 

# 값 출력
for i in range(1,n+1):
    for j in range(1,n+1):
        if edges[i][j] !=INF:
            print(edges[i][j],end=' ')
        else:
            print(0,end=' ')
    print()