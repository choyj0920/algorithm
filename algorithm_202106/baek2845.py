# baek2845 파티가 끝나고 난 뒤
import sys
input=sys.stdin.readline

a,b=map(int,input().split())
temp=a*b

arr=list(map(int,input().split()))
arr=[i -temp for i in arr]
print(*arr)