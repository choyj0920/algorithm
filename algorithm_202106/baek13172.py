# baek13172 Σ
import sys
import math
ans=0
input=sys.stdin.readline
MOD = 1_000_000_007
def power(base, p):
    ans = 1
    cur = base
    while p > 0:
        ans = (cur * ans) % MOD if (p & 1) else ans
        cur = (cur * cur) % MOD
        p //= 2
    return ans
for t in range(int(input())):
    n,s=map(int,input().split())
    temp=math.gcd(n,s)
    n//=temp
    s//=temp
    temp=power(n,MOD-2)
    ans+= s*temp %MOD
    ans %= MOD
print(ans)