# baek14938 서강그라운드
import heapq, sys

INF = 99999999999999999999999

vertex, limit, edge = map(int, sys.stdin.readline().split())
item = list(map(int, sys.stdin.readline().split()))

adj = [[] for _ in range(vertex)]
for i in range(edge):
    x,y,z = map(int, sys.stdin.readline().split())
    adj[x - 1].append((y - 1, z))
    adj[y - 1].append((x - 1, z))
    
def dijstra(v):
    d[v] = 0
    min_q = []
    min_q.append((d[v], v))
    while len(min_q) != 0:
        distance = min_q[0][0]
        current = min_q[0][1]
        heapq.heappop(min_q)
        if d[current] < distance:
            continue
        for i in range(len(adj[current])):
            next = adj[current][i][0]
            nextdistance = adj[current][i][1] + distance
            if nextdistance < d[next]:
                d[next] = nextdistance
                heapq.heappush(min_q, (nextdistance, next))
                
ans = 0
for i in range(vertex):
    d = [INF] * vertex
    dijstra(i)
    cnt = item[i]
    for j in range(vertex):
        if d[j] != 0 and d[j] <= limit:
            cnt += item[j]

    if ans < cnt:
        ans = cnt
print(ans)