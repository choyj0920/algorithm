# baek18291 비요뜨의 징검다리 건너기
import sys
input=sys.stdin.readline
T=int(input())
MOD=1_000_000_007
def solution(n):
    ans = 1
    cur = 2
    while n > 0:
        ans = (cur * ans) % MOD if (n & 1) else ans
        cur = (cur * cur) % MOD
        n //= 2
    return ans

for _ in range(T):
    n=int(input())
    print(solution(n-2))
    