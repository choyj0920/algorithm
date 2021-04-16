# baek15824 너 봄에는 캡사이신이 맛있단다
import sys
input=sys.stdin.readline
MOD=1_000_000_007
N=int(input())
arr=[0]+list(map(int,input().split()))
pow=[0]*(300005)

arr.sort()
pow[0]=1
ans=0

for i in range(1,300001):
    pow[i]=pow[i-1]*2% MOD
for i in range(1,N+1):
    ans=(ans+(pow[i-1]-pow[N-i]+MOD) % MOD * arr[i]) % MOD
print(ans)

