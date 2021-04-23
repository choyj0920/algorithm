# baek17143 낚시왕
import sys
input=sys.stdin.readline
R,C,M=map(int,input().split())
arr=[[ [] for _ in range(C+1)] for _ in range(R+1)]
shark=dict()
for i in range(1,M+1):
    # r0,c1 위치 , s2 -속력, d3 이동방향 (1-위 ,2- 아래,3-오른쪽,4-왼쪽), z4 크기
    r, c, s, d, z= map(int,input().split())
    shark[i]=[r,c,s,d,z]
    arr[r][c].append(i)
ans=0
def fishing(col):
    global ans,arr,shark
    for i in range(1,R+1):
        if len(arr[i][col]) > 0:
            sharknum= arr[i][col][0]
            ans+= shark[sharknum][4]
            arr[i][col]=[]
            del shark[sharknum]            
            break

def moving():
    global arr,shark
    for sharknum,info in shark.items():
        arr[info[0]][info[1]].remove(sharknum)
        posR,posC,direct=info[0],info[1],info[3]
        if info[3] ==1: # 위로 이동
            posR-= info[2]
            if posR<1:
                direct=2
                posR = -posR +1
        elif info[3]==2: # 아래로 이동
            posR+= info[2]
            if posR >R:
                direct=1
                posR= 2*R-posR

        elif info[3]==3: # 우측이동
            posC+= info[2]
            if posC >C:
                direct=4
                posC= 2*C-posC
        else:  # 왼쪽 이동
            posC-= info[2]
            if posC<1:
                direct=3
                posC = -posC +1

        arr[posR][posC].append(sharknum)
        shark[sharknum][0],shark[sharknum][1],shark[sharknum][3]=posR,posC,direct
    
    for i in range(1,R+1):
        for j in range(1,C+1):
            if len(arr[i][j]) >1:
                temp=arr[i][j]
                maxindex,maxZ=0,-1
                for i in temp:
                    if shark[i][4]>maxZ:
                        maxindex=i
                        maxZ=shark[i][4]
                
                arr[i][j]=[maxindex]
                for i in temp:
                    if i !=maxindex:
                        del shark[i]            
                        
                    

            


for i in range(1, C+1):
    fishing(i)
    moving()
print(ans)
    
    
    

    