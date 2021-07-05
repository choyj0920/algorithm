# baek2530 인공지능 시계
import sys
input =sys.stdin.readline

a,b,c=map(int,input().split())
t=int(input())
c +=t
b+= c//60
c = c%60
a+= b//60
b = b%60

a = a%24
print(a,b,c)