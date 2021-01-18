# baek1007 벡터매칭

import sys
import math
input=sys.stdin.readline
arr=[]
n=0
def solution(c,p,m,vectorx,vectory):
    if n==c:
        return math.sqrt(vectorx*vectorx+vectory*vectory)
    _min=1e10
    if (p<n//2):
        r=solution(c+1,p+1,m,vectorx+arr[c][0],vectory+arr[c][1])
        if r<_min : _min=r
    if (m<n//2):
        r=solution(c+1,p,m+1,vectorx-arr[c][0],vectory-arr[c][1])
        if r<_min : _min=r

    return _min

T=int(input())
for _ in range(T):
    n=int(input())
    arr=[]
    dist=[]
    for _ in range(n):
        arr.append(list(map(int,input().split())))

    print(round(solution(0,0,0,0,0),6))
