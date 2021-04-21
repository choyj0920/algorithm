# baek12916 K-Path
import sys
input=sys.stdin.readline
MOD=1_000_000_007
N,K=map(int,input().split())
base=[list(map(int,input().split())) for _ in range(N)]

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
ans=0
temp=pow(base,K)
for i in temp:
    for j in i:
        ans+=j
print(ans%MOD)
