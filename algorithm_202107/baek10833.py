# baek10833 사과 
ans=0
for i in range(int(input())):
    a,b=map(int,input().split())
    ans += b%a
print(ans)