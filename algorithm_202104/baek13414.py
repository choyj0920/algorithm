# baek13414 수강신청
import sys
input=sys.stdin.readline

Klist=dict()
k,l=map(int,input().split())
for i in range(l):
    temp=input().rstrip()
    Klist[temp]=i

for key in sorted(Klist, key=Klist.__getitem__)[:k]:
        print(key)