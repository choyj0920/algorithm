# baek13511 트리와 쿼리2
import sys
from math import log2
from collections import deque
input=sys.stdin.readline

n=int(input())
logN=int(log2(n)+1)
tree =[[] for _ in range(n+1)] # 각노드의 연결 노드
for _ in range(n-1):
    a,b,c=map(int,input().split())
    tree[a].append([b,c])
    tree[b].append([a,c])

depth=[0 for _ in range(n+1)]   # 부모노드 개수
cost=[0 for _ in range(n+1)]   # 루트노드에서 그노드까지 비용
# 2^k 번쨰 부모노드 저장
# log2 1000000 
st=[[0 for _ in range(logN)] for i in range(n+1)] 
# st[a][b] =[a의 2^b 번째 부모노드]

visited=[False for _ in range(n+1)] # bfs 방문

# bfs 트리 생성
q=deque()
q.append(1) # 루트
visited[1] =True
cost[1]=0
while q:
    p=q.popleft()
    for i,d in tree[p]:
        if not visited[i]:
            q.append(i)
            cost[i]=cost[p]+d
            st[i][0]=p
            visited[i] = True
            depth[i]=depth[p]+1

for j in range(1,logN): # 희소 테이블 설정
    for i in range(1,n+1):
        st[i][j]=st[st[i][j-1]][j-1]
        
def findLCA(u,v):
    if depth[u]<depth[v]:
        u,v=v,u
    # 둘의 레벨 차이
    dif =depth[u]-depth[v]
    
    for i in range(logN):
        if dif&(1<<i):
            u=st[u][i]
            
    if u==v:    # 같으면 출력
        return u
    
    for i in range(logN-1,-1,-1): # 루트 부터 내려가다가 처음달라지는 순간 노드
        if st[u][i] != st[v][i] and st[u][i] != 0 and st[v][i] !=0:
            u=st[u][i]
            v=st[v][i]
            
    return st[u][i]

def  findKthNode(u,v,k): # k 번째 노드 찾는함수
    lcaNode=findLCA(u,v)
    leftDiffu= depth[u]-depth[lcaNode]
    rightDiffv= depth[v]-depth[lcaNode]

    # lcaNode 를 중심에 두고  u랑 가깝다면
    if k<=leftDiffu+1: # lca 노드 포함
        dif =k-1 # k번째가 u,v도 포함하므로
        i=0
        while dif: # 차이만큼 ㄱㄱ
            if (dif&1): u =st[u][i]
            dif >>=1
            i+=1
        return u
    else:  # lcaNode 를 중심에 두고  v랑 가깝다면
        dif = rightDiffv- (k- leftDiffu -1) # k번째가 u,v도 포함하므로
        i=0
        while dif:
            if (dif&1): v =st[v][i]
            dif >>=1
            i+=1
        return v

m= int(input())
for _ in range(m):
    temp =list(map(int,input().split()))
    u,v=temp[1:3]
    if temp[0] == 1:
        print(cost[u] + cost[v] - (cost[findLCA(u,v)]* 2))
    elif temp[0]==2:
        k=temp[3]
        print(findKthNode(u,v,k))
