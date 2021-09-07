# baek15953 상금 헌터

reward17=[0]+[500]+[300]*2+[200]*3+[50]*4+[30]*5+[10]*6
reward18=[0]+[512]+[256]*2+[128]*4+[64]*8+[32]*16
cut17=21
cut18=31

for i in range(int(input())):
    ans=0
    a,b=map(int,input().split())
    if a<=cut17:
        ans+= reward17[a]
    if b<=cut18:
        ans+= reward18[b]
    print(ans*10000)