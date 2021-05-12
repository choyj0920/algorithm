# baek17219 비밀번호 찾기
import sys
input=sys.stdin.readline
n,m=map(int,input().split())
password=dict()
for _ in range(n):
    temp=input().split()
    password[temp[0]]=temp[1]
for _ in range(m):
    print(password[input().strip()])