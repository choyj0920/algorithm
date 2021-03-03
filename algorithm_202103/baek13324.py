# baek13324 BOJ 수열2
import sys
import heapq
input=sys.stdin.readline
n=int(input())
arr=list(map(int,input().split()))

ans=0 
pq=[]
anslist=[0]*n
for i in range(n):
    heapq.heappush(pq,-arr[i])
    anslist[i]=-pq[0]
    if len(pq)>0 and arr[i] < -pq[0]:
        ans+= -pq[0]-arr[i]
        heapq.heappop(pq)
        heapq.heappush(pq,-arr[i])
for i in range(n-2,-1,-1):
    anslist[i]=min(anslist[i],anslist[i+1])

for i in anslist:
    print(i)

