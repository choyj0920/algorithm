# baek17435 합성함수와 쿼리

import sys
import math
input=sys.stdin.readline

m=int(input())
arr= [0]+list(map(int,input().split()))
MAXLOG2=int(math.log2(500002) +1) # 2^i<= 500002 i 최대값
# sp 테이블 sparseTable[n][x] x가  2^n번 이동 했을때 값
sparseTable= [[0 for col in range(m+1)] for row in range(MAXLOG2)] 

for i in range(1,m+1):      # x가 2*0=1 이동 했을 때 값
    sparseTable[0][i]=arr[i]


for i in range(1,MAXLOG2): # n 1~maxlog2 까지 값
    for j in range(1,m+1):
        # j 가 2^i 간 것은 = j가 2^(i-1)간 곳에서 2^(i-1) 만큼 가는 것
        sparseTable[i][j]=sparseTable[i-1][sparseTable[i-1][j]]


q= int(input())
for _ in range(q):
    n,x=map(int,input().split())
    cur=x
    for i in range(MAXLOG2,-1,-1):
        if n & (1<<i):
            cur=sparseTable[i][cur] # 2^i 만큼 이동
    print(cur)


