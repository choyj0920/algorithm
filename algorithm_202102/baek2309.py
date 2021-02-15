# baek2309 일곱난쟁이
import sys
input=sys.stdin.readline
arr=[int(input()) for _ in range(9)]
arr=sorted(arr)
cnt=0
for _ in range(9):
    cnt+=arr[_]
def solution():
    for i in range(8):
        for j in range(i+1,9):
            if cnt-arr[i]-arr[j]==100:
                return i,j
    return False,0

i,j=solution()
for _ in range(9):
    if _ is not i and _ is not j:
        print(arr[_])
