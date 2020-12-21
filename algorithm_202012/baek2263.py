# baek2263 트리의 순회

import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**6)

n=int(input())
inorder=list(map(int,input().split()))
postorder=list(map(int,input().split()))

pos=[0]*(n+1)
for i in range(n):
    pos[inorder[i]]=i

def divide(in_start,in_end,p_start,p_end):
    if (in_start>in_end) or (p_start>p_end):
        return
    parents=postorder[p_end]
    print(parents,end=" ")          # 후위 순회
    
    left = pos[parents]-in_start    # 좌측 갯수
    right= in_end-pos[parents]      # 우측 갯수

    divide(in_start,in_start+left-1,p_start,p_start+left-1)
    divide(in_end-right+1,in_end,p_end-right,p_end-1)
    
divide(0, n-1,0, n-1)
    