# baek12728 N제곱 계산 
import sys
input=sys.stdin.readline
T=int(input())
MOD=1000
base=[
    [6 ,-4],
    [1, 0]
]

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

for i in range(T):
    n=int(input())
    temp= pow(base,n-1)
    print("Case #",i+1,": ", format((temp[0][0]*6+temp[0][1]*2+999)%MOD,'03'),sep="")

    