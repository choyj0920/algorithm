# baek3584 최소공통조상

import sys
input=sys.stdin.readline

T =int(input())
while T>0:
    n=int(input())
    parent=[0 for _ in range(n+1)] # 각노드의 부모노드 저장
    for i in range(n-1):
        a,b=map(int,input().split())
        parent[b]=a

    a,b= map(int,input().split())
    parent_a=[a]
    parent_b=[b]

    while parent[a]:    # 루트에 도달 할때까지 a 부모노드를 리스트
        parent_a.append(parent[a])
        a=parent[a]
    while parent[b]:    # 루트에 도달 할때까지 b 부모노드를 리스트
        parent_b.append(parent[b])
        b=parent[b]   
    
    i=len(parent_a)-1
    j=len(parent_b)-1
    while parent_a[i]==parent_b[j]: # 루트 부터 최소 공통 조상 바로 다음까지
        i-=1
        j-=1
    print(parent_a[i+1])




    T-=1