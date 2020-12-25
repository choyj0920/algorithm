# baek2162 선분그룹
import sys
input=sys.stdin.readline

# sys.setrecursionlimit(10**9) 이게 들어가면 메모리초과가 뜬다..

n=int(input())
arr=[ list(map(int,input().split())) for _ in range(n)]
parent=[_ for _ in range(n)]

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
    a= getParent(a)
    b= getParent(b)
    if a==b: return True
    return False

def ccw(x1,y1,x2,y2,x3,y3):         # 외적 삼각형 넓이
    temp =x1*y2+x2*y3+x3*y1 +(-y1*x2 - y2*x3-y3*x1)

    if temp<0:      # 시계
        return -1
    elif temp==0:   # 일직선
        return 0 
    else:           # 반시계
        return 1
def check(d1, d2):
    a=d1[:2]
    b=d1[2:]
    c=d2[:2]
    d=d2[2:]
    result1=ccw(*a,*b,*c) * ccw(*a,*b,*d)
    result2=ccw(*c,*d,*a) * ccw(*c,*d,*b)
    if result1 ==0 and result2 == 0:
        if a>b: a,b=b,a
        if c>d: c,d=d,c
        if a<=d and c<=b:
            return True
        else:
            return False

    elif result1 <=0 and result2 <= 0:
        return True
    else:
        return False

for i in range(n-1):
    for j in range(i+1,n):        
        if check(arr[i],arr[j]):
            unionParent(i,j)

cnt =[0 for _ in range(n)]
maxcnt=0
ans=0
for i in range(len(parent)):
    temp =getParent(i)
    cnt[temp] +=1
    maxcnt=max(maxcnt,cnt[temp])
    if  temp ==i:
        ans+=1
print(ans)
print(maxcnt)

