# baek14860 GCD 곱

import sys
input=sys.stdin.readline
check=[False]*(15000002)
MOD=1_000_000_007

def pow(m,t):
    ans = 1
    cur = m
    while t > 0:
        ans = (cur * ans) % MOD if (t & 1) else ans
        cur = (cur * cur) % MOD
        t //= 2
    return ans

n,m=map(int,input().split())
if n>m:
    n,m=m,n
t=0
j=2
while j<=n: # gcd곱에 들어가는 2의 개수 t
    t+=((n//j)*(m//j))
    j*=2

p=pow(2,t)
for i in range(4,n+1,2): # 2의 배수 소수 아니라고 체크
    check[i]=True
for i in range(3,n+1,2): 
        if not check[i]:
            t,j=0,i
            while j<=n:
                t+=((n//j)*(m//j))
                j*=i

            p=(p*pow(i,t))%MOD

            for j in range(i*i,n+1,i*2):
                check[j]=True 
    
print(p)



    