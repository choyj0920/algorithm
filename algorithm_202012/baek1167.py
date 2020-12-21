# baek1167 트리의 지름
# 트리의 지름을 구하는 방법은 정해져있다. 
# 먼저 임의의 정점부터 모든 정점까지의 거리를 구하여 
# 가장 먼 거리를 가진 정점을 구한다. 
# 그 후에 그 정점으로부터 모든 정점까지의 거리를 다시 구해서 
# 그 거리들 중 가장 먼 값이 트리의 지름이 된다.

import sys
input=sys.stdin.readline
# input
v = int(input())

# variable init
edge=[[] for _ in range(v+1)]
visited=[False for _ in range(v+1)]

maxIndex=0          # 최대 값 index
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
for _ in range(1,v+1):      
    temp=input().split()
    x=int(temp[0])
    for j in range(1,len(temp)-1,+2):
        edge[x].append([int(temp[j]),int(temp[j+1])])


# 임의의 노드(1)에서 dfs(bfs)수행 후 
dfs(1,0)
# 가장 먼 노드에서 다시 dfs(bfs)수행 하면
for _ in range(v+1): visited[_]=False
dfs(maxIndex,0)
# 이때 나온 최장 거리가 트리의 지름
print(maxDistance)

