# baek1094 막대기
import sys
import heapq
x=int(sys.stdin.readline())
q=[64]
cnt=64
while cnt!=x:
    if x < cnt:
        temp=heapq.heappop(q)
        temp /= 2
        heapq.heappush(q,temp)
        if x <= cnt-temp:
            cnt-=temp
        else:
            heapq.heappush(q,temp)
    

print(len(q))