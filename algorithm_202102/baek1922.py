# baek1922 네트워크 연결
import sys
input=sys.stdin.readline
n=int(input())
m=int(input())
edges=[list(map(int,input().split())) for _ in range(m)]
edges=sorted(edges,key = lambda x: x[2])
parent=[_ for _ in range(n+1)]
def getParent(a):
    if parent[a]==a:
        return a
    else:
        return getParent(parent[a])

def checkunion(a,b):
    return getParent(a)==getParent(b)

def union(a,b):
    a=getParent(a)
    b=getParent(b)
    if a<b:
        parent[a]=b
    else:
        parent[b]=a

cnt=0
ans=0
for a,b,c in edges:
    if not checkunion(a,b):
        cnt+=1
        ans+=c
        union(a,b)
        if cnt>=n-1:
            break
print(ans)
