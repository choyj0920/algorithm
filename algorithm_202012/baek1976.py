# baek1976 여행가자

import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)

n=int(input())
m=int(input())
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

for i in range(1,n+1):
    temp=list(map(int,input().split()))
    for j in range(1,n+1):
        if temp[j-1] ==1:
            unionParent(parent,i,j)

path=list(map(int,input().split()))
check=True
for j in range(m-1):
    if not checkUnion(parent,path[j],path[j+1]) :
        print("NO")
        check=False
        break
if check:
    print("YES")
        
    
        
            
        


    
    
    