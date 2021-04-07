# baek14731 謎紛芥索紀-미분개xx (Large)
import sys 
input=sys.stdin.readline

MOD = int(1_000_000_007)
def solution(a):
    if a<0:
        return 0
    result =1
    cur=2
    while a:
        if a & 1:
            result = result * cur % MOD 
        cur =cur *cur % MOD
        a //= 2
    return result

ans=0
for i in range(int(input())):
    a,b =map(int,input().split())
    ans+=a*b*solution(b-1)
print(ans % MOD)
    