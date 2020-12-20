# baek 9019 DSLR

import sys
input=sys.stdin.readline

def exD(num):
    return (int(num)*2)%10000
def exS(num):
    return ((int(num)-1)+10000)%10000
def exL(num):
    temp=str(num).zfill(4)
    return int(temp[1:]+temp[:1])
def exR(num):
    temp=str(num).zfill(4)
    return int(temp[-1:]+temp[:-1])

dslr=[exD,exS,exL,exR] #DSLR각각 함수 배열
str_dslr="DSLR"

T=int(input()) # 테스트 케이스 갯수
while T>0:
    dp=[''for _ in range(10001)]
    a,b =map(int,input().split())
    dp[a]="0"
    que=[a]
    
    while len(que)>0:
        x=que.pop(0)
        path=dp[x]
        for i in range(4):
            next=dslr[i](x)
            if dp[next]=='':
                dp[next]=path+str_dslr[i] # 이전과정의 경로를 모두 포함하여 오래걸림
                que.append(next)
                if next==b:
                    que=[]
                    break    

    print(dp[b][1:])

    T-=1

    
    
    