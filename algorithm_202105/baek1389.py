# baek1389 케빈 베이컨의 6단계 법칙
import sys
input=sys.stdin.readline
n,m=map(int,input().split())
edges=[[] for _ in range(n+1)]
for _ in range(m):
    a,b=map(int,input().split())
    edges[a].append(b)
    edges[b].append(a)

def solution(node):
    visited=[False]*(n+1)
    visited[node]=0
    que=[node]
    ans=0
    while que:
        cur=que.pop(0)
        dis=visited[cur]
        
        for next in edges[cur]:
            if visited[next] == False:
                visited[next]=dis+1
                ans+=dis+1
                que.append(next) 
    
    return ans

anslist=[]
for i in range(1,n+1):
    anslist.append([solution(i),i])
anslist.sort()
print(anslist[0][1])
