# baek13430 합 구하기 
import sys
input=sys.stdin.readline
MOD=1_000_000_007


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

K,N=map(int,input().split())
if N==1:
    print(1)
else:
    base=[[0]*(K+2) for _ in range(K+2)]
    for i in range(K+2):
        for j in range(K+2):
            if i>=j:
                base[i][j]=1
    ans=0
    temp = pow(base,N-1)
    for i in range(K+2):
        ans+= temp[K+1][i]
    print(ans%MOD)
