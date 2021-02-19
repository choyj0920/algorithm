# baek2583 영역 구하기
import sys
input=sys.stdin.readline
xx=[0,0,-1,1]
yy=[-1,1,0,0]

m,n,k=map(int,input().split())
visited=[[0]* m for _ in range(n)]
for _ in range(k):
    x1,y1,x2,y2=map(int,input().split())
    for i in range(x1,x2):
        for j in range(y1,y2):
            visited[i][j]=1
ans=[]
def bfs(x,y):
    cnt=0
    que=[(x,y)]
    visited[x][y]=1
    cnt+=1
    while len(que)>0:
        x,y=que.pop(0)
        for _ in range(4):
            nx,ny=x+xx[_],y+yy[_]
            if 0<=nx<n and 0<=ny<m:
                if visited[nx][ny] ==0:
                    visited[nx][ny]=1
                    que.append((nx,ny))
                    cnt+=1
    ans.append(cnt)
cnt=0
for i in range(n):
    for j in range(m):
        if visited[i][j]==0:
            cnt+=1
            bfs(i,j)
print(cnt)
print(*sorted(ans))