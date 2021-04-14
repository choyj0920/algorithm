# baek17401 일하는세포
import sys
input=sys.stdin.readline
MOD=1_000_000_007
T,N,D=map(int,input().split())
sepoMap=[]
for _ in range(T):
    m=int(input())
    temp= [[0]*N for i in range(N)]
    for i in range(m):
        a,b,c=map(int,input().split())
        temp[a-1][b-1]=c
    sepoMap.append(temp)

def matrixMul(a,b):
    result=[[0]*len(b[0]) for _ in range(len(a))]
    for i in range(len(a)):
        for j in range(len(b)):
            for k in range(len(b[0])):
                result[i][k]= (result[i][k]+ a[i][j]*b[j][k]) % MOD

    return result

def pow(a,n):
    result=[[0]*len(a) for _ in range(len(a))]
    for i in range(len(a)): 
        result[i][i]=1

    while n:
        if n&1: 
            result=matrixMul(result,a)
        n//=2
        a=matrixMul(a,a)
    
    return result

Tcount= D//T
leftcount= D%T
ans=[[0]*N for _ in range(N)]
for i in range(N): 
    ans[i][i]=1
if Tcount > 0:
    for i in range(T):
        ans=matrixMul(ans,sepoMap[i])
    ans=pow(ans,Tcount)
for i in range(leftcount):
    ans=matrixMul(ans,sepoMap[i])

for i in ans:
    print(*i)
    
    