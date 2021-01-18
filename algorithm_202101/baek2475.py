# baek2475 검증수

arr=list(map(int,input().split()))
cnt=0
for i in arr:
    cnt+=i*i
print(cnt%10)