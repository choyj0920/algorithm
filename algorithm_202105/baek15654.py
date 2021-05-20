# baek15654 N과 M

from itertools import permutations

n,m=map(int,input().split())
arr = list(map(int, input().split()))
arr = sorted(arr) #순서대로 나오게 정렬 먼저

for numbers in list(permutations(arr, m)):
    print(*numbers)
    