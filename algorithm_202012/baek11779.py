# baek11779 최소비용 구하기2 

import sys

input=sys.stdin.readline

n=int(input())
m=int(input())

INF =int(1e9)

# 입력 ,변수 초기화
edges=[[INF for i in range(n+1)]for _ in range(n+1)]
for _ in range(m):
    a,b,c= map(int,input().split())
    edges[a][b]= min(c,edges[a][b])     # 경로가 같은데 비용이 다른 것 있다는 언급이 없었지만 생각했어야..
start_city,end_city=map(int,input().split())

costs=[INF for i in range(n+1)]         # 다익스트라 start_city에서의 거리 배열
parents=[0 for i in range(n+1)]         # 경로 추적용 이전위치
visitied=[False for i in range(n+1)]

def find_lowest_cost_node(costs):       # 다익스트라 최단거리 찾는 함수
    lowest_cost=INF
    lowest_cost_node=None
    for node in range(len(costs)):
        cost= costs[node]
        if cost<lowest_cost and visitied[node]==False:
            lowest_cost=cost
            lowest_cost_node=node
    return lowest_cost_node    

# 다익스트라
node = start_city
costs[start_city]=0
visitied[start_city]=True
while node is not None:
    cost= costs[node]
    neighbors=edges[node]
    for i in range(len(neighbors)):
        new_cost=cost+neighbors[i]
        if costs[i]> new_cost: # 현재 가지고 있는 cost보다 최단 거리 라면
            costs[i]=new_cost
            parents[i]=node
    visitied[node]=True
    node = find_lowest_cost_node(costs)

print(costs[end_city])

trace=[]
current=end_city
while current != start_city:
    trace.append(current)
    current=parents[current]
trace.append(start_city)
trace.reverse()
print(len(trace))
for i in trace:
    print(i,end=' ')


