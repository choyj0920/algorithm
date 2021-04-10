# baek2500 복불복
import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)
N,K,T=map(int,input().split())
MOD =42043
arr=[0]*T
for _ in range(T):
    temp=int(input())
    arr[temp]+=1

def solution(leftTurns,rest):
    if(leftTurns==0):
        return 1
    sum=0
    for i in range(len(arr)):
        if arr[i] != 0  and rest >= i:  
            sum += solution(leftTurns-1,rest-i)*arr[i]
    return sum % MOD

print(solution(N,K))