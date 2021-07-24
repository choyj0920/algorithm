# baek1547 공 
ans= 1
for i in range(int(input())):
    a,b=map(int,input().split())
    if a == ans:
        ans = b
    elif b== ans:
        ans = a
print(ans)