# baek15666 N과 M(12)
from itertools import combinations_with_replacement

n,m=map(int,input().split())

a=list(map(int,input().split()))
a.sort()
a=list(combinations_with_replacement(a, m))

a=sorted(list(set(a)))

for i in a:
    print(*i)