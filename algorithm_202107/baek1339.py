# baek1399 단어 수학
arr =dict()
for i in range(65,91):
    arr[chr(i)]=0
for i in range(int(input())):
    ss=input().rstrip()
    k=len(ss)-1
    for j in ss:
        arr[j] += (10**k)
        k-=1
arr =sorted(arr.items(),key =lambda x: x[1],reverse=True)

ans =0
value=9
for c,cnt in arr:
    if cnt==0:
        break
    ans +=value*cnt
    value-=1
    
print(ans)