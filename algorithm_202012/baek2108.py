# 백준 2108 통계학
import sys
from collections import Counter


num=[0 for i in range(8001)]

#input
n= int(sys.stdin.readline())
arr=[0 for i in range(n)]
cnt=0

for _ in range(n):
    temp= int(sys.stdin.readline())
    arr[_]=temp
    cnt+=temp

# 산술 평균
ave =round(cnt/n)
print(ave)

# arr sort
arr=sorted(arr)
# 중간 값
print(arr[n//2])

count = Counter(arr)
count = sorted(count.items(),key = lambda x : (-x[1],x[0]))

if n>1 and count[0][1]== count[1][1]:
    print(count[1][0])
else:
    print(count[0][0])

print(arr[n-1]-arr[0])


