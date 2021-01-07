# baek17472 다리만들기2
import sys
input=sys.stdin.readline

sys.setrecursionlimit(10**9)

# input
n,m=map(int,input().split())
arr=[ list(map(int,input().split())) for _ in range(n)]

move =[[-1,0],[1,0],[0,1],[0,-1]]
bridge=dict()

# 섬 구분 위한 bfs - 같은 섬인 칸들을 같은 index로 초기화
def bfs(x,y,index): # index 섬의 종류 섬의 종류는 2부터 인덱스 arr의 섬 input값이 1이여서 걍 귀차나서
    que=[[x,y]]     # 첫 que
    arr[x][y]=index
    while que:
        current=que.pop(0)
        for i in range(4): # 4방향으로 이동
            nextx=current[0]+move[i][0]
            nexty=current[1]+move[i][1]
            if 0<= nextx<n and 0<=nexty <m:
                if arr[nextx][nexty]==1:
                    que.append([nextx,nexty])
                    arr[nextx][nexty]=index

# 다리를 구하는 함수 재귀 함수로 일직선으로 쭉 이동하게해서
def dfs(x,y, k,brigeleng,start):
    nx=x+move[k][0] # 다음칸 x,y
    ny=y+move[k][1]
    if not 0<= nx<n or not 0 <=ny<m:    # 이탈 제외
        return
    end= arr[nx][ny]    # 현재 값 바다인지 어떤 섬인지
    if end != 0:        # 현재 값이 바다가 아니면 ->   섬내 이동이거나
        if end == start:        # 섬내 이동이였다.
            return
        if brigeleng==1:        # 다리의 길이는 2이상이여야 하므로 1이면 안됨!
            return
        else:                   # 인정받을수 잇는 다리이면
            
            temp=str(min(start,end))+str(max(start,end))    # a,b 를 연결하는 다리를 딕셔너리로 
                        # 이 dic 인덱싱은 이문제만 된다 이문제는 섬의갯수가 최대 6개라..가능
            if bridge.get(temp) != None:                    # dic에 그런 다리가 존재 한다면!
                bridge[temp] = min(bridge[temp],brigeleng)  # 짧은 값으로 저장해주게
            else:
                bridge[temp]=brigeleng                      # dic에 없었으면 그냥 지정
            return
    brigeleng +=1               # 다음 칸 이동이니 값을 하나 증가
    dfs(nx,ny,k,brigeleng,start)
        
        



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



cnt=2 # 섬 index 2부터 시작하게~
for i in range(n):
    for j in range(m):
        if arr[i][j]==1: # 이 위치가 바다가 아니면
            bfs(i,j,cnt) # 이 기점부터 같은 섬인 칸 다 bfs로 찾기
            cnt+=1

islandcount=cnt-2   # 섬 개수

# 다리 찾기
for i in range(n):
    for j in range(m):
        if arr[i][j]: 
            for k in range(4):
                dfs(i,j,k,0,arr[i][j])

bridges=[]  # 다리 배열 정렬을 위해 짧은 것부터
for key,value in bridge.items():
    start=int(key[0])   # 시작 점
    end= int(key[1])    # 도착 점 - 사실 다리라서 그냥 index숫자가 작은섬이 시작점 
    bridges.append([value,start,end]) # 배열에 넣고

bridges=sorted(bridges)         # 정렬

# 유니온 파인드를 위한 부모값 저장 배열
parent=[_ for _ in range(cnt)]
count=0     # 다리 갯수 count를 위한 변수 다리갯수= 섬의수-1 이 되면 모든 섬이 연결!
answer=0    # 이어진 다리 길이들의 합
for i in bridges:   # 다리 길이가 짧은것 부터 연결
    if checkUnion(parent,i[1],i[2]): # 이미 연결된 섬끼리면 다음으로
        continue
    unionParent(parent,i[1],i[2])   #  연결이 되어있지 않은 섬이라면 연결
    answer += i[0]  # 값 증가
    count+=1        # 값 증가
    if count>=islandcount-1: # 모든 섬이 연결되었으면 종료
        break
    

if count>=islandcount-1:
    print(answer)
else:
    print(-1)
