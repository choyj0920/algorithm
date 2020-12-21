# baek1967 트리의 지름

import sys
input=sys.stdin.readline

sys.setrecursionlimit(10**9)    # 이 문제는 재귀가 3000보다 더 발생해
                                # 이 재귀 최대값을 늘려야한다

# input
v = int(input())

# variable init
edge=[[] for _ in range(v+1)]
visited=[False for _ in range(v+1)]

maxIndex=1          # 최대 값 index
maxDistance=0       # 최대 값

def dfs(node ,cost):        #dfs함수
    global maxDistance
    global maxIndex
    if visited[node] != False:  #첫 방문 시에만 진행
        return
    
    if maxDistance < cost:  # 최대값 설정
        maxDistance = cost
        maxIndex =node
    
    visited[node] =True        # 방문 설정

    for next,dis in edge[node]: # 연결된 노드 dfs
        dfs(next,cost+dis)

    
# input
for _ in range(1,v):      
    a,b,c=map(int,input().split())
    edge[a].append([b,c])
    edge[b].append([a,c])


# 임의의 노드(1)에서 dfs(bfs)수행 후 
dfs(1,0)
# 가장 먼 노드에서 다시 dfs(bfs)수행 하면
for _ in range(v+1): visited[_]=False
dfs(maxIndex,0)
# 이때 나온 최장 거리가 트리의 지름
print(maxDistance)

