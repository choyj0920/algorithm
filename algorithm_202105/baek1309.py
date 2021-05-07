# baek1309 동물원
import sys
input=sys.stdin.readline
n=int(input())
MOD=9901

a,b,c=1,1,1

for i in range(2,n+1):
    _a,_b,_c=a,b,c
    a=(_b+_c)%MOD
    b=(_a+_c)%MOD
    c=(_a+_b+_c)%MOD


print(sum([a,b,c])%MOD)
    