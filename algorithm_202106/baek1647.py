# baek1647 도시 분할 계획
import sys
input=sys.stdin.readline

n,m=map(int,input().split())
edges=[]
parent=[i for i in range(n+1)]

# union-find 함수들
def getParent(x):    # 부모 노드를 찾는 함수
    if parent[x]==x : return x
    parent[x]=getParent(parent[x])
    return parent[x]


def unionParent(a,b):# 두 부모 노드를 합치는 함수
    a= getParent(a)
    b= getParent(b)
    if a<b: parent[b]=a
    else : parent[a]=b

def checkUnion(a,b): # 두 노드가 같은 부모노드를 가지는지 확인하는 함수
    a= getParent( a)
    b= getParent( b)
    if a==b: return True
    return False
# union-find 함수들


def main():
    for i in range(m):
        a,b,c=map(int,input().split())
        edges.append((a,b,c))
    edges.sort(key=lambda x: x[2])
    count=0
    ans=0
    for a,b,c in edges:
        if checkUnion(a,b):
            continue
        unionParent(a,b)
        ans+=c
        count+=1
        if count>=n-2:
            break
    print(ans)

if __name__ == '__main__':
    main()
    