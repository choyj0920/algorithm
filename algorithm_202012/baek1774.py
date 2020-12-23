# baek1774 우주신과의 교감
import sys
input=sys.stdin.readline

sys.setrecursionlimit(10**9)

# union-find 함수들
def getParent(parent,x):    # 부모 노드를 찾는 함수
    if parent[x]==x : return x
    parent[x]=getParent(parent,parent[x])
    return parent[x]


def unionParent(parent,a,b):# 두 부모 노드를 합치는 함수
    a= getParent(parent,a)
    b= getParent(parent,b)
    if a<b: parent[b]=a
    else : parent[a]=b

def checkUnion(parent,a,b): # 두 노드가 같은 부모노드를 가지는지 확인하는 함수
    a= getParent(parent, a)
    b= getParent(parent, b)
    if a==b: return True
    return False
# union-find 함수들

def distance(a,b):
    return ((a[0]-b[0])**2 + (a[1]-b[1])**2)**0.5


# input
n,m= map(int,input().split())
stars= [list(map(float,input().split())) for _ in range(n)]
cnt= 0              # 현재 연결된 정점 갯수 확인을 위한
parent=[ _ for _ in range(n)]
for _ in range(m):
    a,b=map(int,input().split())
    if not checkUnion(parent,a-1,b-1):
        unionParent(parent,a-1,b-1)
        cnt+=1
        
edges=[]
for i in range(n):  # 각 별사이 거리 간선 
    for j in range(n):
        if i != j:
            edges.append([distance(stars[i],stars[j]),i,j])
edges=sorted(edges)
total_weight=0      # 최소 가중치 합 
for weight,a,b in edges:    # 정렬된 간선으로 반복문
    if not checkUnion(parent,a,b):  # 현재 간선의 두 정점이 연결되어 있지 않으면
        total_weight+=weight        # 최소 가중치 합에 포함
        cnt+=1
        unionParent(parent,a,b)     # 연결되었음을 union-find 기법으로
        if cnt>=n-1:                # 모두 연결되엇으면-종료
            break

print("%.2f"%total_weight)
