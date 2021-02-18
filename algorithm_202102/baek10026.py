# baek10026 적록색약
import sys
input=sys.stdin.readline
n=int(input())
arr=[list(map(str,input().strip())) for _ in range(n)]
xx=[0,0,-1,1]
yy=[-1,1,0,0]
visited=[[0]*n for _ in range(n)]
def bfs(i,j):
    color=arr[i][j]
    visited[i][j]=1
    que=[[i,j]]
    while len(que)>0:
        cur=que.pop(0)
        for i in range(4):
            next=[cur[0]+xx[i],cur[1]+yy[i]]
            if 0<=next[0]<n and 0<=next[1]<n :
                if visited[next[0]][next[1]] ==0 and arr[next[0]][next[1]]==color:
                    visited[next[0]][next[1]]=1
                    que.append([next[0],next[1]])
def bfs2(i,j):
    isBlue=arr[i][j]=="B"
    visited[i][j]=1
    que=[[i,j]]
    while len(que)>0:
        cur=que.pop(0)
        for i in range(4):
            next=[cur[0]+xx[i],cur[1]+yy[i]]
            if 0<=next[0]<n and 0<=next[1]<n :
                if visited[next[0]][next[1]] ==0 and (arr[next[0]][next[1]]=='B')==(isBlue):
                    visited[next[0]][next[1]]=1
                    que.append([next[0],next[1]])

cnt=0
for i in range(n):
    for j in range(n):
        if visited[i][j]==0:
            bfs(i,j)
            cnt+=1
print(cnt,end=' ')
cnt=0
visited=[[0]*n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if visited[i][j]==0:
            bfs2(i,j)
            cnt+=1
print(cnt)



