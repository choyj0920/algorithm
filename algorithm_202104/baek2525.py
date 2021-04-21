# baek2525 오븐기계
import sys
input=sys.stdin.readline
h,m=map(int,input().split())
aa=int(input())

m+=aa
h+=(m//60)
m%=60
h%=24
print(h,m)