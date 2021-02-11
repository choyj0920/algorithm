# baek2193 이친수
n=int(input())
arr=[[0,0] for _ in range(n+1)]
arr[0][1]=1
for _ in range(1,n):
    arr[_][0]=arr[_-1][0]+arr[_-1][1]
    arr[_][1]=arr[_-1][0]

print(arr[n-1][0]+arr[n-1][1])
