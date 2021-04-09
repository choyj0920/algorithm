# baek14440 정수 수열
import sys
input=sys.stdin.readline
x,y,a0,a1,n= map(int,input().split())
MOD=100
base=[
    [x,y],
    [1,0]
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
if n != 0:
    temp=pow(base,n-1)
    temp=format(((temp[0][0]*a1+temp[0][1]*a0)% MOD),'02')
    print(temp)
else:
    print(a0)
