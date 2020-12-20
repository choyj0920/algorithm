# baek 13913 숨바꼭질 4

import sys
input=sys.stdin.readline

paths=[[1,1],[-1,1],[0,2]]
MAX=100001
soobin,sis= map(int ,input().split())
dp=[[0,0] for _ in range(MAX)]   #dp[i] = [i까지의 최단경로, i칸 이전 위치]

dp[soobin]=[1,-1]        # 시작점 설정
que=[soobin]                  # que 초기화

_max=min(max(soobin,sis)*2,MAX)
while(len(que)!=0):
    x= que.pop(0)
    _cnt=dp[x][0]
    for i in range(3):
        a=(x+paths[i][0])*paths[i][1]
        if 0<=a<_max:
            if dp[a][0] ==0:
                dp[a]=[_cnt+1,x]
                que.append(a)
                if a==sis:
                    que=[]

answer =dp[sis][0]-1
ans_path=dp[sis][1]

print(answer)
ans_paths=[sis]
x=sis
while x != soobin:
    x=dp[x][1]
    ans_paths.append(x)
for i in range(len(ans_paths)-1,-1,-1):
    print(ans_paths[i],end= ' ')
    

                
    
    