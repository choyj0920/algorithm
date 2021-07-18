# baek15656 N과 M (7)
from itertools import product

N, M = map(int, input().split())
N_list = list(map(int, input().split()))
N_list = sorted(N_list) #순서대로 나오게 정렬 먼저

N_list=product(N_list,repeat=M)
for i in N_list:
    print(*i)