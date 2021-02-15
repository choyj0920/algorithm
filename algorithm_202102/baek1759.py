# baek1759 암호 만들기
import sys
from itertools import combinations
input=sys.stdin.readline
vowels = ['a', 'e', 'i', 'o', 'u']
L, C = map(int, input().split())
pwd = sorted(list(map(str, input().split())))

comb = combinations(pwd, L)

for c in comb:
    count = 0
    for letter in c:
        if letter in vowels:
            count += 1
    if (count >= 1) and (count <= L-2): # 모음이 한개 이상, 자음이 두개 이상
        print(''.join(c))