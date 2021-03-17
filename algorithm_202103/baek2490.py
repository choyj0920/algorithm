# baek2490 윷놀이
import sys
input=sys.stdin.readline

ss=["E","A","B","C","D"]
for _ in range(3):
    cnt=0
    for i in list(map(int,input().split())):
        if i==0:
            cnt+=1
    print(ss[cnt])
