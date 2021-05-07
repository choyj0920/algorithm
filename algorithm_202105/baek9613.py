# baek9613 GCD 합
import sys
import itertools
input = sys.stdin.readline

def gcd(a, b):
    return gcd(b, a % b) if b else a

t = int(input())
for i in range(t):
    num_list = list(map(int, input().split()))
    num_list = num_list[1:]
    ans = 0
    for a, b in itertools.combinations(num_list, 2):
        ans += gcd(a, b)
    print(ans)