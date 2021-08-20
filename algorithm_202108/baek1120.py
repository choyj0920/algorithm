# baek1120 문자열
s1,s2 =map(str,input().split())
n=len(s2)-len(s1)
ans=len(s2)
for i in range(n+1):
    cnt=0
    for j in range(len(s1)):
        if s1[j] != s2[j+i]:
            cnt+=1
        
    if ans > cnt :
        ans=cnt

print(ans)
