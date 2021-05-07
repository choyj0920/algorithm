# baek1006 습격자 초라기
import sys 
input=sys.stdin.readline
T= int(input())

def solution(start,a,b,c):
    for i in range(start,N):
        # i열까지 최소
        a[i+1] = min(b[i]+1,c[i]+1)
        if arr1[i]+arr2[i]<=W : # i열의 1행과 2행을 한 소대로 커버 가능하면
            a[i+1]=min(a[i+1],a[i]+1)
        if i >0 and arr1[i-1]+arr1[i] <=W and arr2[i-1]+arr2[i] <=W : 
            # 1행의 i열, i-1을 한소대로 2행의 i열,i-1열을 한소대로
            a[i+1]=min(a[i+1],a[i-1]+2)

        if i<N-1:
            # 1행은 i+1열, 2행은 i열까지 최소 소대 수
            b[i+1] = a[i+1] + 1
            if arr1[i+1] + arr1[i] <= W: # c[i]에서 1행만 두칸 채우는것이 한소대로 커버가능하면
                b[i+1] = min(b[i+1], c[i] + 1)

            # 1행은 i열, 2행은 i+1열까지 최소 소대 수
            c[i+1] = a[i+1]+1
            if arr2[i+1] + arr2[i] <= W: # b[i]에서 2행만 두칸 채우는것이 한소대로 커버가능하면
                 c[i+1] = min(c[i+1], b[i] + 1)
    return a,b,c
        

for _ in range(T):
    N,W=map(int,input().split())
    # 적의 수
    arr1=list(map(int,input().split()))
    arr2=list(map(int,input().split()))

    # 1행과 2행을 모두 i-1까지 채울 때 최소 소대수
    a=[0 for _ in range(N+1)]
    # 1행은 i열까지  2행은 i-1까지 채울 때 최소 소대수
    b=[0 for _ in range(N+1)]
    # 1행은 i-1열까지  2행은 i까지 채울 때 최소 소대수
    c=[0 for _ in range(N+1)]

    a[0]=0
    b[0]=1
    c[0]=1
    a,b,c=solution(0,a,b,c)
    res=a[N]

    # 1행의 0번 열과 끝 열이 쌍을 이룰 수 있을 때 다시 한 번 계산 후 최솟값 갱신
    # 1행의 0번 열이 이미 채워졌다고 생각
    if N > 1 and arr1[0] + arr1[N-1] <= W:
        a[1] = 1
        b[1] = 2 # 2행의 0번열, 1행의 1번열에 쌍을 이룰 수 없는 채로 2개의 소대를 배치해야함.
        if arr2[0] + arr2[1] <= W: c[1] = 1 # 2행의 0번 열과 1번 열이 쌍을 이룰 수 있는 경우
        else: c[1] = 2
        
        a, b, c = solution(1, a, b, c)
        res = min(res, c[N-1] + 1)

    # 2행의 0번 열과 끝 열이 쌍을 이룰 수 있을 때 다시 한 번 계산 후 최솟값 갱신
    # 2행의 0번 열이 이미 채워졌다고 생각
    if N > 1 and arr2[0] + arr2[N-1] <= W: 
        a[1] = 1
        c[1] = 2 # 1행의 0번열, 2행의 1번열에 쌍을 이룰 수 없는 채로 2개의 소대를 배치해야함.
        if arr1[0] + arr1[1] <= W: b[1] = 1 # 윗줄의 0번 열과 1번 열이 쌍을 이룰 수 있는 경우
        else: b[1] = 2
        
        a, b, c = solution(1, a, b, c)
        res = min(res, b[N-1] + 1)

    # 1행과 2행 모두 0번 열과 끝 열이 쌍을 이룰 수 있을 때 다시 한 번 계산 후 최솟값 갱신
    # 1행과 2행 모두 0번 열이 이미 채워졌다고 생각
    if N > 1 and arr1[0] + arr1[N-1] <= W and arr2[0] + arr2[N-1] <= W:
        a[1] = 0 # 0열이 이미 채워짐
        b[1] = 1
        c[1] = 1

        a, b, c = solution(1, a, b, c)
        res = min(res, a[N-1] + 2)
    
    print(res)