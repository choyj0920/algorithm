# baek15683 감시
from sys import stdin
from itertools import product
import copy

input = stdin.readline

n, m = map(int,input().strip().split())
board = [[int(i) for i in input().strip().split()] for _ in range(n)]
visited = [[0]*m for _ in range(n)]
camera = []
answer = []

for i in range(n):
    for j in range(m):
        temp = []
        if board[i][j] == 1: #x,y,d,c_num
            temp.append((i, j, 0, 1))
            temp.append((i, j, 1, 1))
            temp.append((i, j, 2, 1))
            temp.append((i, j, 3, 1))
            camera.append(temp)
        elif board[i][j] == 2:
            temp.append((i, j, 0, 2))
            temp.append((i, j, 1, 2))
            camera.append(temp)
        elif board[i][j] == 3:
            temp.append((i, j, 0, 3))
            temp.append((i, j, 1, 3))
            temp.append((i, j, 2, 3))
            temp.append((i, j, 3, 3))
            camera.append(temp)
        elif board[i][j] == 4:
            temp.append((i, j, 0, 4))
            temp.append((i, j, 1, 4))
            temp.append((i, j, 2, 4))
            temp.append((i, j, 3, 4))
            camera.append(temp)
        elif board[i][j] == 5:
            temp.append((i, j, 0, 5))
            camera.append(temp)

if len(camera)>1:
    com = list(product(*camera))
else:
    com = copy.deepcopy(camera)

#1번 경우 4가지, 2번 경우 2가지, 3번 경우 4가지, 4번 경우 4가지, 5번 경우 1가지

def bf():
    dx = (-1,0,1,0) #북동남서
    dy = (0,1,0,-1)
    while com:
        a = com.pop()
        c_visited = copy.deepcopy(board)
        for x,y,d,c in a: #x,y,d,c_num
            if len(camera) == 1:
                c_visited = copy.deepcopy(board)
            c_visited[x][y] = 7
            nx = x
            ny = y
            nx_1 = x
            ny_1 = y
            nx_2 = x
            ny_2 = y
            nx_3 = x
            ny_3 = y
            nx_4 = x
            ny_4 = y
            if c == 1: #camera 1
                while True:
                    nx += dx[d]
                    ny += dy[d]
                    if nx<0 or ny<0 or nx>=n or ny>=m:
                        break
                    if board[nx][ny] == 6:
                        break
                    c_visited[nx][ny] = 7
            elif c == 2: #camera 2
                while True:
                    if d == 0:
                        nx_1 -= 1
                        if nx_1<0  or nx_1>=n:
                            break
                        if board[nx_1][y] == 6:
                            break
                        c_visited[nx_1][y] = 7
                    elif d == 1:
                        ny_1 -= 1
                        if ny_1<0 or ny_1>=m:
                            break
                        if board[x][ny_1] == 6:
                            break
                        c_visited[x][ny_1] = 7
                while True:
                    if d == 0:
                        nx_2 += 1
                        if nx_2<0  or nx_2>=n:
                            break
                        if board[nx_2][y] == 6:
                            break
                        c_visited[nx_2][y] = 7
                    elif d == 1:
                        ny_2 += 1
                        if ny_2<0 or ny_2>=m:
                            break
                        if board[x][ny_2] == 6:
                            break
                        c_visited[x][ny_2] = 7
            elif c == 3: #camera 3
                while True:
                    nx_1 += dx[d]
                    ny_1 += dy[d]
                    if nx_1<0 or ny_1<0 or nx_1>=n or ny_1>=m:
                        break
                    if board[nx_1][ny_1] == 6:
                        break
                    c_visited[nx_1][ny_1] = 7
                while True:
                    nx_2 += dx[(d+1)%4]
                    ny_2 += dy[(d+1)%4]
                    if nx_2<0 or ny_2<0 or nx_2>=n or ny_2>=m:
                        break
                    if board[nx_2][ny_2] == 6:
                        break
                    c_visited[nx_2][ny_2] = 7
            elif c == 4: #camera 4
                while True:
                    nx_1 += dx[d]
                    ny_1 += dy[d]
                    if nx_1<0 or ny_1<0 or nx_1>=n or ny_1>=m:
                        break
                    if board[nx_1][ny_1] == 6:
                        break
                    c_visited[nx_1][ny_1] = 7
                while True:
                    nx_2 += dx[(d+1)%4]
                    ny_2 += dy[(d+1)%4]
                    if nx_2<0 or ny_2<0 or nx_2>=n or ny_2>=m:
                        break
                    if board[nx_2][ny_2] == 6:
                        break
                    c_visited[nx_2][ny_2] = 7
                while True:
                    nx_3 += dx[(d+2)%4]
                    ny_3 += dy[(d+2)%4]
                    if nx_3<0 or ny_3<0 or nx_3>=n or ny_3>=m:
                        break
                    if board[nx_3][ny_3] == 6:
                        break
                    c_visited[nx_3][ny_3] = 7
            elif c == 5: #camera 5
                while True:
                    nx_1 += dx[d]
                    ny_1 += dy[d]
                    if nx_1<0 or ny_1<0 or nx_1>=n or ny_1>=m:
                        break
                    if board[nx_1][ny_1] == 6:
                        break
                    c_visited[nx_1][ny_1] = 7
                while True:
                    nx_2 += dx[(d+1)%4]
                    ny_2 += dy[(d+1)%4]
                    if nx_2<0 or ny_2<0 or nx_2>=n or ny_2>=m:
                        break
                    if board[nx_2][ny_2] == 6:
                        break
                    c_visited[nx_2][ny_2] = 7
                while True:
                    nx_3 += dx[(d+2)%4]
                    ny_3 += dy[(d+2)%4]
                    if nx_3<0 or ny_3<0 or nx_3>=n or ny_3>=m:
                        break
                    if board[nx_3][ny_3] == 6:
                        break
                    c_visited[nx_3][ny_3] = 7
                while True:
                    nx_4 += dx[(d+3)%4]
                    ny_4 += dy[(d+3)%4]
                    if nx_4<0 or ny_4<0 or nx_4>=n or ny_4>=m:
                        break
                    if board[nx_4][ny_4] == 6:
                        break
                    c_visited[nx_4][ny_4] = 7
            count = 0
            for i in range(n):
                for j in range(m):
                    if c_visited[i][j] == 7 or c_visited[i][j] == 6:
                        count += 1
            answer.append(((n*m)-count))


if len(camera)==0:
    cnt=0
    for i in range(n):
        for j in range(m):
            if board[i][j]==0:
                cnt+=1
    print(cnt)
else:
    bf()
    print(min(answer))