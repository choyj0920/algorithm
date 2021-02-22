# baek1100 하얀칸
import sys
input=sys.stdin.readline
cnt=0
for i in range(8):
    temp=list(map(str,input().strip()))
    for j in range(8):
        if (i+j)%2==0 and temp[j]=="F":
            cnt+=1
print(cnt)