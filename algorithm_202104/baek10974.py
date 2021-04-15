# baek10974 모든 순열
from itertools import permutations
N = int(input())
arr = [i for i in range(1, N+1)]

for numbers in list(permutations(arr)):
    print(*numbers)