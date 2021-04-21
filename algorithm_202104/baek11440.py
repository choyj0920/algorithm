# baek11440 피보나치 수의 제곱의 합
import sys 
input=sys.stdin.readline
MOD=1_000_000_007
fibobase=[[1,1],[1,0]]
N=int(input())


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

print((pow((N))[0][0]*pow((N-1))[0][0])%MOD)