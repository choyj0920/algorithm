# baek1620 나는야 포켓몬 마스터 이다솜
import sys
input=sys.stdin.readline
dogam_num=dict()
dogam_name=dict()
n,m=map(int,input().split())
for i in range(1,n+1):
    temp=input().rstrip()
    dogam_name[temp]=i
    dogam_num[str(i)]=temp

for i in range(m):
    temp=input().rstrip()
    if temp in dogam_num:
        print(dogam_num[temp])
    else:
        print(dogam_name[temp])