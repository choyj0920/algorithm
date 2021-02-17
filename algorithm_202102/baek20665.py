# baek20665 독서실 거리두기
import sys
import heapq
input=sys.stdin.readline
n,t,p=map(int,input().split())
p-=1
arr=[]
for i in range(t):
    a,b=map(int,input().split())
    if a==b: 
        continue
    arr.append([a,b,i])

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
    h1=before // 100
    m1=before % 100
    h2=after // 100
    m2=after % 100
    ans =(h2 - h1) * 60
    ans+= m2 - m1

    return ans

que= []
cnt=0
temp=900
i =0
while i<len(arr) or len(que) !=0 :
    if i<len(arr) and (len(que)==0 or arr[i][0] < que[0][0]): # 입실 
        
        intime,outtime,per=arr[i]
        sit =findmindis()
        check[sit]=per
        heapq.heappush(que,[outtime,sit])
        if p==sit:
            cnt+=caltime(temp,intime)
        i+=1
    else:  # 퇴실
        outtime,sit=heapq.heappop(que)
        check[sit]= -1
        if p== sit:
            temp=outtime
        pass

        
cnt+=caltime(temp,2100)
print(cnt)
