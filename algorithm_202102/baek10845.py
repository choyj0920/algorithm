# baek10845 큐
import sys
input=sys.stdin.readline
que=[]
for _ in range(int(input())):
    temp=input().split()
    if temp[0]=="push":
        que.append(int(temp[1]))
    elif temp[0]=="pop":
        print(que.pop(0) if len(que)!=0 else -1)
    elif temp[0]=="size":
        print(len(que))
    elif temp[0]=="empty":
        print(1 if len(que)==0 else 0)
    elif temp[0]=="front":
        print(que[0] if len(que)!=0 else -1)
    elif temp[0]=="back":
        print(que[-1] if len(que)!=0 else -1)
        