# baek2506 점수계산
n=int(input())
arr=list(map(int,input().split()))
before=0
ans=0
for i in arr:
    if i==1:
        before+=1
        ans +=before

    else:
        before=0
print(ans)