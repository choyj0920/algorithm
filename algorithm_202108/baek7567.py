# baek7567 그릇
arr=input().strip()
ans=10
for i in range(1,len(arr)):
    if arr[i-1] == arr[i]:
        ans+=5
    else:
        ans +=10

print(ans)