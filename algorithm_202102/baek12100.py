# baek12100 2048(easy)
from collections import deque
import sys,copy
input=sys.stdin.readline
n=int(input())
arr=[list(map(int,input().split())) for _ in range(n)]
maxvalue=0
def dfs(mode,maps,cnt): # mode가 0이면 위로 ,1이면 아래로,2이면 좌로,3이면 우로
    global maxvalue
    copy_maps=copy.deepcopy(maps)
    if mode==0: # 위로 이동
        for i in range(n): # 
            temp=deque()
            for j in range(n): # 위에 칸부터
                if copy_maps[j][i]!=0: # 빈 칸이 아닐 때에만
                    temp.append(copy_maps[j][i])
            num=0
            while num +1 <len(temp):
                if temp[num]== temp[num+1]:
                    temp[num]=0
                    temp[num+1] *= 2
                    num +=2
                else:
                    num+=1
            num=0
            while num < n:
                if temp:
                    a = temp.popleft()
                    if a != 0:
                        copy_maps[num][i] = a
                        num += 1
                else:
                    copy_maps[num][i] = 0
                    num += 1
    elif mode == 1: # 아래로 이동 
        for i in range(n):
            temp = deque()
            for j in range(n - 1, -1, -1):  # 밑에 칸부터 
                if copy_maps[j][i] != 0:
                    temp.append(copy_maps[j][i])
            num = 0 
            while num + 1 < len(temp):
                if temp[num] == temp[num + 1]:
                    temp[num] = 0
                    temp[num + 1] *= 2
                    num += 2
                else:
                    num += 1
            num = n - 1
            while num > -1:
                if temp:
                    a = temp.popleft()
                    if a != 0:
                        copy_maps[num][i] = a
                        num -= 1
                else:
                    copy_maps[num][i] = 0
                    num -= 1
    elif mode == 2: # 좌로 이동
        for i in range(n): # 
            temp=deque()
            for j in range(n): # 좌측 칸부터
                if copy_maps[i][j]!=0: # 빈 칸이 아닐 때에만
                    temp.append(copy_maps[i][j])
            num=0
            while num +1 <len(temp):
                if temp[num]== temp[num+1]:
                    temp[num]=0
                    temp[num+1] *= 2
                    num +=2
                else:
                    num+=1
            num=0
            while num < n:
                if temp:
                    a = temp.popleft()
                    if a != 0:
                        copy_maps[i][num] = a
                        num += 1
                else:
                    copy_maps[i][num] = 0
                    num += 1
        pass
    elif mode == 3:  # 우로 이동
        for i in range(n):
            temp = deque()
            for j in range(n - 1, -1, -1):  # 우측 칸부터 
                if copy_maps[i][j] != 0:
                    temp.append(copy_maps[i][j])
            num = 0 
            while num + 1 < len(temp):
                if temp[num] == temp[num + 1]:
                    temp[num] = 0
                    temp[num + 1] *= 2
                    num += 2
                else:
                    num += 1
            num = n - 1
            while num > -1:
                if temp:
                    a = temp.popleft()
                    if a != 0:
                        copy_maps[i][num] = a
                        num -= 1
                else:
                    copy_maps[i][num] = 0
                    num -= 1
    if cnt==5:
        for i in range(n):
            maxvalue=max(maxvalue,max(copy_maps[i]))
        return
    for i in range(4):
        dfs(i,copy_maps,cnt+1)

for i in range(4):
    dfs(i,arr,1)
print(maxvalue)