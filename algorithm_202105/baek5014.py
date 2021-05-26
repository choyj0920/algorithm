# baek5014 스타트 링크
import sys
input=sys.stdin.readline
F,S,G,U,D =map(int,input().split())
visited=[False]*(F+1)


def bfs():
    visited[S]=0
    q=[S]
    if S==G:
        return 0
    while q:
        node=q.pop(0)
        cnt=visited[node]
        upper_next=node+U
        down_next=node-D
        if upper_next<=F and visited[upper_next] is False:
            q.append(upper_next)
            visited[upper_next]=cnt+1
            if upper_next== G:
                return cnt+1
        if down_next >=1 and visited[down_next] is False:
            q.append(down_next)
            visited[down_next] = cnt+1
            if down_next==G:
                return cnt+1
    return "use the stairs"

print(bfs())

        
            
            