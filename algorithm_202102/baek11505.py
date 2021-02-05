# baek11505 구간 곱 구하기
import sys
import math
sys.setrecursionlimit(10**9)
input=sys.stdin.readline

# update
def update(node, start, end, idx, val): # 세그먼트 트리 업데이트 함수
    if idx < start or end < idx: # 범위를 벗어났으면 종료
        return

    if start == end:  # 마지막 노드 
        tree[node] = val
        return

    mid = (start + end) // 2
    update(node*2,start,mid,idx,val) # 현재노드의 좌측 업데이트
    update(node*2+1,mid+1,end,idx,val) # 현재노드의 우측 업데이트
    tree[node] = (tree[node*2] * tree[node*2+1]) % 1000000007  # 좌측 노드* 우측노드

# query
def query(node, start, end, left, right): # 노드 곱 쿼리
    if right < start or end < left: # 없는 자리면, 곱셈의 항등원 1리턴
        return 1

    if left <= start and end <= right: # 노드의 아래가 모두 포함 되면 전체 포함
        return tree[node]

    mid = (start + end) // 2
    tmp = query(node*2,start,mid,left,right) * query(node*2+1,mid+1,end,left,right) # 좌측 우측 노드 곱 (포함 범위만)
    return tmp % 1000000007        # 나머지만 리턴

# main
n, m, k = [int(x) for x in input().split()]

h = int(math.ceil(math.log2(n)))
t_size = 1 << (h+1)

arr = []
tree = [0] * t_size

for i in range(n):
    num = int(input())
    arr.append(num)
    update(1,0,n-1,i,num)

for _ in range(m+k):
    a, b, c = [int(x) for x in input().split()]

    if a == 1:  # 노드 값 변경
        arr[b-1] = c
        update(1,0,n-1,b-1,c)
    elif a == 2: # 노드들 곱 쿼리
        print(query(1,0,n-1,b-1,c-1))