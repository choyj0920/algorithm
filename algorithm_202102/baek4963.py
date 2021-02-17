# baek4963 섬의 개수
import sys
input=sys.stdin.readline
arr=[]
visited=[]
w,h=0,0
dx=[0,0,-1,1,1,-1,1,-1]
dy=[-1,1,0,0,1,-1,-1,1]
def bfs(x,y):
    que=[[x,y]]
    visited[x][y]=True
    while len(que) != 0:
        cur=que.pop(0)
        for _ in range(8):
            xx=cur[0]+dx[_]
            yy=cur[1]+dy[_]
            if 0<=xx < h and 0<=yy<w:
                if arr[xx][yy]==1 and visited[xx][yy]==0:
                    que.append([xx,yy])
                    visited[xx][yy]=1
    
while True:
    cnt=0
    w,h=map(int,input().split())
    if w==0 and h==0:
        break
    arr=[list(map(int,input().split())) for _ in range(h)]
    visited=[[0]*w for _ in range(h)]
    for i in range(h):
        for j in range(w):
            if arr[i][j]==1 and visited[i][j] ==0:
                bfs(i,j)
                cnt+=1
    
    print(cnt)
        

