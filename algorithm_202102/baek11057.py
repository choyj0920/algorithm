# baek11057 오르막 수
n = int(input())

arr=[[0]*10 for i in range(n)]
arr[0]=[1 for i in range(10)]
ans=0
for i in range(1,n):
    for j in range(10):
        for k in range(j+1):
            arr[i][j] += arr[i-1][k]
for i in range(10):
    ans+=arr[n-1][i]
    
print(ans%10007)