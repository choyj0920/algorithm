# baek13323 BOJ수열1
import sys
import heapq
input=sys.stdin.readline
n=int(input())
arr=list(map(int,input().split()))

pq=[]
result=0
for i in range(n):
    num=arr[i]-i
    heapq.heappush(pq,-num)
    
    if len(pq)>0 and -pq[0] >num:
        result += -pq[0]-num
        heapq.heappop(pq)
        heapq.heappush(pq,-num)

print(result)