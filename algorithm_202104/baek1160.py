# baek1160 Random Number Generator
import sys
input=sys.stdin.readline
m,a,c,X0,n,g =map(int,input().split())
base=[
    [a,1],
    [0,1] ]
MOD=m

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

temp = pow(base,n)
ans= (temp[0][0]*X0 + temp[0][1]*c)% m % g
print(ans)

