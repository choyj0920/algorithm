# baek15655 N과 M (6)
from itertools import combinations

N, M = map(int, input().split())
N_list = list(map(int, input().split()))
N_list = sorted(N_list) #순서대로 나오게 정렬 먼저

for numbers in list(combinations(N_list, M)): #조합 메써드 이용
    for num in numbers:
        print(num, end=' ')
    print()