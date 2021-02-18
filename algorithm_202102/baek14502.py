# # baek14502 연구소
s = []
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
max_result = 0
def bfs():
    global max_result
    copy = [[0] * m for i in range(n)]
    for i in range(n):
        for j in range(m):
            copy[i][j] = s[i][j]
    result = 0
    arr = []
    for i in range(n):
        for j in range(m):
            if copy[i][j] == 2:
                arr.append([i, j])
    while arr:
        a, b = arr[0][0], arr[0][1]
        del arr[0]
        for i in range(4):
            ax = a + dx[i]
            ay = b + dy[i]
            if 0 <= ax and 0 <= ay and ax < n and ay < m:
                if copy[ax][ay] == 0:
                    copy[ax][ay] = 2
                    arr.append([ax, ay])
    for i in copy:
        for j in i:
            if j == 0:
                result += 1
    max_result = max(max_result, result)
def wall(cnt):
    if cnt == 3:
        bfs()
        return
    for i in range(n):
        for j in range(m):
            if s[i][j] == 0:
                s[i][j] = 1
                wall(cnt + 1)
                s[i][j] = 0
n, m = map(int, input().split())
for i in range(n):
    s.append(list(map(int, input().split())))
wall(0)
print(max_result)


# import sys
# from collections import deque
# import copy
# input=sys.stdin.readline
# n,m=map(int,input().split())
# xx = (0,0,1,-1)
# yy = (1,-1,0,0)
# arr = [[int(i) for i in input().strip().split()] for _ in range(n)]
# visited = [[0]*m for _ in range(n)]
# ans=0
# virus=[]

# virus = []
# for i in range(n):
#     for j in range(m):
#         if arr[i][j] == 2:
#             virus.append((i,j))
# que=deque()           

# def bfs():
#     global ans
#     c_visited = copy.deepcopy(visited)
    
#     for a,b in virus:
#         que.append((a,b))
#         while que:
#             x,y=que.popleft()
#             for i in range(4):
#                 nx,ny=x+xx[i],y+yy[i]
#                 if 0<=nx<n and 0<=ny<m:
#                     if arr[nx][ny] == 0 and c_visited[nx][ny]==0:
#                         c_visited[nx][ny] = 1
#                         que.append((nx,ny))
                        
#     cnt=0
#     for i in range(n):
#         for j in range(m):
#             if arr[i][j] != 0 or c_visited[i][j] !=0:
#                 cnt+=1
#     ans=max(ans,n*m-cnt)
    

# def makewall(depth, start):
#     if depth==3:
#         bfs()
#         return
#     for i in range(start, n*m):
#         r = i // m
#         c = i % n
#         if arr[r][c] == 0:
#             arr[r][c] = 1
#             makewall(depth+1, i+1)
#             arr[r][c] = 0


# makewall(0,0)

# print(ans)
            
