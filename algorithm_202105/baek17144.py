# baek17144 미세먼지
import sys
input=sys.stdin.readline
R, C, T = map(int, input().split(" "))

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

field = []
for _ in range(R):
    field.append(list(map(int, input().split(" "))))

# 공기청정기 찾기
now = (0, 0)
for i in range(R):
    if field[i][0] == -1 and field[i+1][0] == -1:
        now = (i, i+1)
        break


for _ in range(T):

    # 확산
    new = [[0 for _ in range(C)] for _ in range(R)]

    for i in range(R):
        for j in range(C):

            if field[i][j] >= 5: # 5보다 작으면 주변에 확산되지 않음

                # 주변에 인접한 칸 당 확산될 양 
                each = field[i][j] // 5
                
                # 주변에 나눠준 수
                count = 0

                # 인접 칸 확산
                for k in range(4):
                    
                    ndr = i + dr[k]
                    ndc = j + dc[k]

                    if 0 <= ndr < R and 0 <= ndc < C and field[ndr][ndc] != -1:
                        
                        count += 1
                        
                        new[ndr][ndc] += each
                
                field[i][j] = field[i][j] - count * each

    # 두 배열 값 합치기 
    for i in range(R):
        for j in range(C):
            field[i][j] += new[i][j]



    # 순환
    # 위쪽 바람 순환
    temp = field[now[0]][C-1] # 뒤에서부터~ 우측으로 이동하는애들
    for i in range(C-2, 0, -1):
        field[now[0]][i+1] = field[now[0]][i]

    temp2 = field[0][C-1] 
    for i in range(now[0]-1):
        field[i][C-1] = field[i+1][C-1]
    field[now[0]-1][C-1] = temp

    temp = field[0][0]
    for i in range(C-1):
        field[0][i] = field[0][i+1]
    field[0][C-2] = temp2

    for i in range(now[0]-1, 1, -1):
        field[i][0] = field[i-1][0]
    field[now[0]][1] = 0
    field[1][0] = temp



    # 아래쪽 바람 순환
    temp = field[now[1]][C-1]
    for i in range(C-2, 0, -1):
        field[now[1]][i+1] = field[now[1]][i]

    temp2 = field[R-1][C-1]
    for i in range(R-1, now[1], -1):
        field[i][C - 1] = field[i-1][C - 1]
    field[now[1]+1][C-1] = temp

    temp = field[R-1][0]
    for i in range(C-1):
        field[R-1][i] = field[R-1][i+1]
    field[R-1][C-2] = temp2

    for i in range(now[1]+1, R-1):
        field[i][0] = field[i+1][0]
    field[now[1]][1] = 0
    field[R-2][0] = temp


# 남은 미세먼지 수
s = 0
for each in field:
    s += sum(each)

print(s+2)