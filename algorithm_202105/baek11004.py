# baek11004 K번째 수
import sys
input=sys.stdin.readline
n,k=map(int,input().split())
arr=list(map(int,input().split()))
arr.sort()
print(arr[k-1])