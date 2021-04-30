# baek1126 같은 탑
import sys
r=sys.stdin.readline
MX=500000
d=[[0]*(MX+1) for _ in range(51)]
n=int(r())
h= [0]+ list(map(int,r().split()))

for i in range(1,MX+1):
    d[0][i]=-1
for i in range(1,n+1):
    for j in range(MX+1):
        d[i][j]=d[i-1][j]
        if j-h[i] >= 0 and d[i-1][j-h[i]] != -1:
            d[i][j]=max(d[i][j],d[i-1][j-h[i]]+h[i])
        if h[i] - j >= 0 and d[i-1][h[i]-j] != -1:
                d[i][j] = max(d[i][j], d[i-1][h[i]-j] + j);
        if j + h[i] <= MX and d[i-1][j+h[i]] != -1:
                d[i][j] = max(d[i][j], d[i-1][j+h[i]])
print(d[n][0] if d[n][0] else -1)
