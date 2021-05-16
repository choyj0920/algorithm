# baek2953 나는 요리사다
ans=0
ansvalue=0
for i in range(1,6):
    temp = sum(list(map(int,input().split())))
    if temp>ansvalue:
        ans=i
        ansvalue=temp
print(ans,ansvalue)