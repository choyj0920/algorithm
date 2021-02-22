# baek1977 완전제곱수
import sys
import math

m=int(sys.stdin.readline())
n=int(sys.stdin.readline())
start=int(math.sqrt(m))
end=int(math.sqrt(n)+1)
flag=False
cnt=0
_min=0
for i in range(start,end):
    if i*i>=m:
        if cnt==0:
            _min=i*i
        cnt+=i*i
           
if cnt==0:
    print(-1)
else:
    print(cnt)
    print(_min)