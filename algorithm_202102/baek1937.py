# baek1937 욕심쟁이 판다
# dp는 신이고 나는 바보다.
import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)
n=int(input())
arr=[list(map(int,input().split())) for _ in range(n)]
dx=[0,0,-1,1]
dy=[-1,1,0,0]
dp=[[0]*n for _ in range(n)]
maxvalue=0
def dfs(i,j):
    global maxvalue
    if dp[i][j] !=0:
        return dp[i][j]
    curcnt=arr[i][j]
    ans=0
    for k in range(4):
        nx,ny=i+dx[k],j+dy[k]
        if 0<=nx<n and 0<=ny<n:
            if curcnt<arr[nx][ny]:
                ans=max(ans,dfs(nx,ny))
    dp[i][j]=ans+1
    maxvalue=max(maxvalue,dp[i][j])
    return dp[i][j]

for i in range(n):
    for j in range(n):
        dfs(i,j)
print(maxvalue)