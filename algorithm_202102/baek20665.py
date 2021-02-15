# baek20665 독서실 거리두기
import sys
input=sys.stdin.readline
n,t,p=map(int,input().split())
p-=1
arr=[]
for i in range(t):
    a,b=map(int,input().split())
    arr.append([a,i,0,b])
    arr.append([b,i,1,a])

arr=sorted(arr)
check=[-1]*n
def findmindis():
    ans,ansdis=110,-3
    for i in range(n):
        if check[i]==-1:
            mindis=101
            for j in range(n):
                if check[j] !=-1:
                    mindis=min(abs(i-j),mindis)
            if mindis==101:
                return 0
            if mindis > ansdis:
                ansdis=mindis
                ans= i
            
    return ans
def caltime(before, after):
    h1=before//100
    m1=before%100
    h2=after//100
    m2=after%100
    ans =(h2-h1)*60
    ans+= m2-m1

    return ans


cnt=0
temp=900
for time,per,isin,ot in arr:
    if isin ==0: # 자리 앉으러옴
        sit=findmindis()
        check[sit]=per
        if p == sit:
            cnt+= caltime(temp,time)
            
    else: # 자리 일어섬
        sit=-1
        for _ in range(n):
            if check[_]==per:
                sit=_
                break
        check[sit]=-1
        if p== sit:
            temp=time
cnt+=caltime(temp,2100)
print(cnt)
