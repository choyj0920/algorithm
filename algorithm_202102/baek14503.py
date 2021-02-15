# baek14503 로봇 청소기
import sys
input=sys.stdin.readline

n,m=map(int,input().split())
r,c,d=map(int,input().split())
arr=[list(map(int,input().split())) for _ in range(n) ]
move =[[-1,0],[0,1],[1,0],[0,-1]]

cnt =0
cur=[r,c,d]
while True:
    if arr[cur[0]][cur[1]] ==0:
        cnt+=1
        arr[cur[0]][cur[1]]=2
    flag=False
    for i in range(4):
        cur[2]= (cur[2]+3)%4
        next=[cur[0]+move[cur[2]][0],cur[1]+move[cur[2]][1]]
        if 0 <= next[0] <n and 0<=next[1]<m:
            if arr[next[0]][next[1]]==0:
                cur[0],cur[1]=next[0],next[1]
                flag=True
                break
            
    if flag == True:
        continue
    temp=(cur[2]+2)%4
    if arr[cur[0]+move[temp][0]][cur[1]+move[temp][1]]== 1:
        break
    cur[0],cur[1]=cur[0]+move[temp][0],cur[1]+move[temp][1]
    
print(cnt)
        



    
    