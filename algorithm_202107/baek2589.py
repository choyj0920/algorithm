# baek2589 보물섬
import sys
sys.setrecursionlimit(10**9)
input=sys.stdin.readline
dx=[-1,1,0,0]
dy=[0,0,-1,1]
n,m=0,0
arr=[]
maxdis=0
treasure=[]

visited=[]
def bfs(x,y,cnt):
    global maxdis,visited
    
    que = [(x,y,0)]

    while que:
        cx,cy,count=que.pop(0)
        print("aaa: ",cx,cy,count)
        visited[cx][cy]=True
        for i in range(4):
            nx=cx+dx[i]
            ny=cy=dy[i]

            if 0<=nx<n and 0<=ny<m and arr[nx][ny] == 'L' and visited[nx][ny]==False:
                if maxdis <count+1:
                    maxdis =count+1
                    print(cx,cy,arr[cx][cy],nx,ny,maxdis)
                
                que.append((nx,ny,count+1))

    return 0
    


def main():
    global n,m,visited,arr
    n,m=map(int,input().split())

    for i in range(n):
        arr.append(input().rstrip())
    
    for i in range(n):
        for j in range(m):
            if arr[i][j] !='W':
                visited=[[False] * m for _ in range(n)]
                print(i,j)
                bfs(i,j,0)
    print(maxdis)

if __name__ == '__main__':
    main()
    