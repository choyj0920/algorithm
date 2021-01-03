# baek1934 최소 공배수
import sys
input = sys.stdin.readline
def gcd(a,b):
    while b:
        r =a%b
        a=b
        b=r
    return a

n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    print(a*b//gcd(a,b))