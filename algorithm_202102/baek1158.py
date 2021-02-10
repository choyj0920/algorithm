# baek1158 요세푸스
n,k=map(int,input().split())

arr=[_ for _ in range(1,n+1)]
ans=[]
index=k-1
while (len(arr)!=0):
    ans.append(arr[index])   
    del arr[index]
    n-=1
    if n==0: break
    index = (index+k-1)%n
print("<",end="")
for _ in range(len(ans)-1):
    print(ans[_],end=", ")
print(ans[-1],">",sep="")
