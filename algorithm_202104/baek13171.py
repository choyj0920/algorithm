# baek13171 A
import sys
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

base = int(input()) % MOD
p = int(input())
print(power(base, p))