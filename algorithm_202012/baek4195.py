# baek4195 친구 네트워크
import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)

def getParent(parent,x):    # 부모 노드를 찾는 함수
    if parent[x]==x : return x
    parent[x]=getParent(parent,parent[x])
    return parent[x]
def setParent(parent,person):
    if person in parent: return
    parent[person]=person
    number[person] = 1

def unionParent(parent,a,b):# 두 부모 노드를 합치는 함수
    a= getParent(parent,a)
    b= getParent(parent,b)
    if a==b: return
    elif a<b: 
        parent[b]=a 
        number[a] += number[b]
    else : 
        parent[a]=b 
        number[b] += number[a]
    


def checkUnion(parent,a,b): # 두 노드가 같은 부모노드를 가지는지 확인하는 함수
    a= getParent(parent, a)
    b= getParent(parent, b)
    if a==b: return True
    return False

tastcase=int(input())
while tastcase>0:
    f=int(input())
    parent={}
    number=dict()
    for _ in range(f):
        temp=input().split()
        setParent(parent,temp[0])
        setParent(parent,temp[1])
        unionParent(parent,temp[0],temp[1]) # 친구 관계 설정
        # 친구 네트워크 수 출력 
        print(number[getParent(parent,temp[0])])
        
    tastcase -= 1
