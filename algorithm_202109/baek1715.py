# baek1715 카드 정렬하기
import heapq
import sys
input=sys.stdin.readline
arr=[]
for i in range(int(input())):
    heapq.heappush(arr,int(input()))

ans=0
while len(arr) > 1:
    a=heapq.heappop(arr)
    b=heapq.heappop(arr)
    ans +=a+b
    heapq.heappush(arr,a+b)

print(ans)