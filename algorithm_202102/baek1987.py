# baek1987 알파벳 -boolean 보다 int가 성능이 좋다.
import sys
input=sys.stdin.readline
R,C=map(int,input().split())
xx=[0,0,-1,1]
yy=[1,-1,0,0] # 이부분도 이차원 배열로 하는거보다 배열 두개로 하는게 성능이 한참 빠름 
arr=[list(map(str,input().strip())) for _ in range(R)]
def to_num(i,j):
    return ord(arr[i][j])-ord('A')

visited = [0]*26
ans = 1
visited[to_num(0,0)]=1

def dfs(i,j,cnt):
    global ans
    ans=max(ans,cnt)
    for k in range(4):
        nx,ny= i+xx[k],j+yy[k]
        if 0 <= nx < R and 0 <= ny < C:
            if visited[to_num(nx,ny)]==0:
                visited[to_num(nx,ny)]=1
                dfs(nx,ny,cnt+1)
                visited[to_num(nx,ny)]=0

dfs(0,0,1)
print(ans)

    