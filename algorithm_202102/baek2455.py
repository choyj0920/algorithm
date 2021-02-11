# baek2455 지능형 기차
cnt=0
_max=0

for _ in range(4):
    a,b=map(int,input().split())
    cnt+= b-a
    _max=max(_max,cnt)

print(_max)