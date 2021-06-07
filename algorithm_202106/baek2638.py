# baek2638 치즈
import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)
n,m =map(int,input().split())
dx=[0,0,1,-1]
dy=[1,-1,0,0]
arr=[list(map(int,input().split())) for _ in range(n)]
cheese=0
for i in range(n):
    cheese += arr[i].count(1)
ans=0

def dfs(cx,cy):
    global cheese
    visited[cx][cy]=True

    for i in range(4):
        nx=cx+dx[i]
        ny=cy+dy[i]
        if 0 <= nx < n and 0 <= ny < m:
            if arr[nx][ny]==0 and visited[nx][ny]==0: # 아직 만나지 않은 빈 공간일 경우
                dfs(nx,ny)
            if arr[nx][ny]==1:
                visited[nx][ny]+=1
                if visited[nx][ny] >=2:
                    cheese -= 1
                    arr[nx][ny]=0

                

    


while cheese != 0:
    ans+=1
    visited=[[0]*m for _ in range(n)]
    dfs(0,0)
print(ans)
    



    
    