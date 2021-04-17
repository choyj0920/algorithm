# baek1533 길의 개수
import sys
input=sys.stdin.readline
MOD=1_000_003
N,S,E,T=map(int,input().split())
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

base=[[0] * (N*5) for _ in range(N*5) ]

for i in range(N):
    temp=input().rstrip()
    for j in range(N):
        if temp[j] !="0":
            dis=int(temp[j])
            base[i*5][j*5+dis-1]=1
    for j in range(1,5):
        base[i*5+j][i*5+j-1]=1

ans=pow(base,T)
print(ans[(S-1)*5][(E-1)*5])
