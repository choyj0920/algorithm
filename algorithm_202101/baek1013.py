# baek1013 Contact
import re
import sys
input=sys.stdin.readline
T = int(sys.stdin.readline())
results = []

for _ in range(T):
    sign = input().strip() # 파이썬 정규 표현식
    p = re.compile('(100+1+|01)+') # 신기 신기
    m = p.fullmatch(sign)
    if m: print("YES")
    else: print("NO")

