# baek13976 타일 채우기 2
import sys
input=sys.stdin.readline

MOD=1_000_000_007
base=[
    [4 ,-1],
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

n=int(input())
if n&1:
    print(0)
else:
    temp=pow(base,n//2-1)
    print((temp[0][0]*3+temp[0][1]*1)%MOD)

    