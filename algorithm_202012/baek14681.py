# baek14681 사분면고르기

import sys

#input
input=sys.stdin.readline
x=int(input())
y=int(input())

if x>0:
    print(1 if y>0 else 4)
else:
    print(2 if y>0 else 3)

