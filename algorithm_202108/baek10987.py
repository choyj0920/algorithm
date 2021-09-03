# baek10987 모음의 개수
iscount=['a','o','e','i','u']
ans=0
for i in input().strip():
    if i in iscount:
        ans+=1
print(ans)