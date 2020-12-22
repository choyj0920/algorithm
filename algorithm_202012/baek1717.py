# baek1717 집합의 표현

import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)

n,m=map(int,input().split())
arr=[-1 for _ in range(n+1)]
parent=[_ for _ in range(n+1)]

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

for _ in range(m):
    check,a,b=map(int,input().split())
    if check==0:
        unionParent(parent,a,b)
    elif check ==1:
        if checkUnion(parent,a,b):
            print("YES")
        else:
            print("NO")

    