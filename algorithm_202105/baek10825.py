# baek10825 국영수
import sys
input=sys.stdin.readline

n=int(input())
arr=[]
for _ in range(n):
    temp=input().rstrip().split()
    arr.append([-int(temp[1]),int(temp[2]),-int(temp[3]),temp[0]])
arr.sort()
for i in arr:
    print(i[3])