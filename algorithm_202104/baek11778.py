# baek11778 피보나치 수와 최대 공약수
import sys 
input=sys.stdin.readline
MOD=1_000_000_007
fibobase=[[1,1],[1,0]]
N,M=map(int,input().split())

def gcd(a,b):
    if b == 0:
        return a
    return gcd(b,a%b)

def matrixMul(a,b):
    temp= [
        [(a[0][0]*b[0][0]+a[0][1]*b[1][0]) % MOD,(a[0][0]*b[0][1]+a[0][1]*b[1][1]) % MOD],
        [(a[1][0]*b[0][0]+a[1][1]*b[1][0]) % MOD,(a[1][0]*b[0][1]+a[1][1]*b[1][1]) % MOD]
        ]
    return temp

def pow(n):
    result=[[1,0],[0,1]]
    cur =fibobase
    while n:
        if n & 1:
            result = matrixMul(result,cur)
        cur =matrixMul(cur,cur)
        n //= 2
    return result
# gcd(F(i),F(j)) = F(gcd(i,j))
# 이부분이 아직도 이해가 안감 , 귀납적 증명을 보긴했는데 머르겠음 유명하다는데 어렵네
print(pow(gcd(N,M)-1)[0][0])