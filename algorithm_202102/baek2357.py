# baek2357 최솟값과 최대값

import sys
input=sys.stdin.readline
a = [int(x) for x in input().split()]
arr=[]
seg=[[0,0]]
do=[]
t=1
cnt=0
ansm=10000000000
ansM=0
for i in range(0,a[0]): # arr 입력
    arr.append(int(input()))

for i in range(0,a[1]):  # 최소 최대 구할 범위 저장
    c = [int(x) for x in input().split()]
    do.append(c)
while t<a[0]:  # 트리 깊이 지정
    t*=2
    cnt+=1
for i in range(0,2**(cnt+1)):
    seg.append([0, 0])


def MM(a,b,c):  # 세그먼트 트리 구간 별 최대 값 구하기
    if a==b:            # 밑에노드가 없으면 바로 이노드 값 리턴
        seg[c][0] = arr[a]
        return seg[c][0]
    else:
        tm1 = MM(a,int((a+b)/2),c*2)        # 왼쪽자식 노드의 최대 값
        tm2 = MM(int((a+b)/2)+1,b,c*2+1)    # 우측자식 노드의 최대값
        if tm1>tm2:                         # 높은 값 저장
            seg[c][0] = tm1
            return tm1
        else:
            seg[c][0] = tm2
            return tm2


def mm(a,b,c):  # 세그먼트 트리 구간 별 최소 값 구하기
    if a==b:
        seg[c][1] = arr[a]      # 밑에 노드가 없으면 바로 이노드 리턴
        return seg[c][1]
    else:
        tm1 = mm(a,int((a+b)/2),c*2)        # 왼쪽 자식 노드의 최소값
        tm2 = mm(int((a+b)/2)+1,b,c*2+1)    # 우측 자식 노드의 최소값
        if tm1<tm2:                         # 작은 값 저장
            seg[c][1] = tm1
            return tm1
        else:
            seg[c][1] = tm2
            return tm2


def com(a,b):  # 세그먼트 트리안의 값 사이의 최소 최대 값을 비교하여 알맞은 값을 리턴합니다.
    max=b[0]   
    min=a[1]
    if a[0]>b[0]:
        max=a[0]
    if a[1]>b[1]:
        min=b[1]
    tmpa=[]
    tmpa.append(max)
    tmpa.append(min)
    return tmpa


def ans(l,r,a,b,c):  # l,r 은 구하려는 범위의 좌우, a,b 는 현재 탐색하고 있는 범위, c는 현재 탐색하고 있는 범위의 세그먼트 트리 좌표입니다.
    
    c1=0
    c2=0
    if l==a and r==b:
        return seg[c]  # 이 노드 전체 포함하는 경우 바로 리턴

    if l<=int((a+b)/2): # a+b 중간 값 이 구하려는 범위 보다 아래 있으면 
        c1+=1
        if r<=int((a+b)/2): # a+b의 중간 값이 구하려는 범위보다 아래있으면
            t1 = ans(l, r, a, int((a + b) / 2), c * 2)  # a~(b노드의 부모노드)로 탐색
        else:
            t1 = ans(l, int((a + b) / 2), a, int((a + b) / 2), c * 2) #  
    if r>int((a+b)/2):
        c2+=1
        if l>int((a+b)/2):
            t2 = ans(l, r, int((a + b) / 2)+1, b, c * 2 + 1)  # 우측 노드 탐색
        else:
            t2 = ans(int((a+b)/2)+1,r,int((a+b)/2)+1,b,c*2+1) # 우측노드
    if c1 and c2:
        return com(t1,t2)
    if c1:
        return t1
    if c2:
        return t2


MM(0,a[0]-1,1)
mm(0,a[0]-1,1)
for i in range(0,len(do)):
    ans1=ans(do[i][0]-1,do[i][1]-1,0,a[0]-1,1)
    print(ans1[1],ans1[0])
    
