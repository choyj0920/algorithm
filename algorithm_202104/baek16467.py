# baek16467 뼝아리의 변신은 무죄
#  삐약삐약
import sys
input=sys.stdin.readline
T=int(input())
MOD=100000007
base=[]

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
for t in range(T):
    K,N=map(int,input().split())
    K+=1
    
    base=[[0]*K for _ in range(K)]
    base[0][0]+=1
    base[0][K-1]+=1
    for _ in range(1,K):
        base[_][_-1]=1
    temp=pow(base,N)
    print(temp[0][0])

    
    