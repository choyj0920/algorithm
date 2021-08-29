# baek1068 트리
n= int(input())
arr=list(map(int,input().split()))
erase=int(input())
root=[]
edges=[[] for i in range(n+1)]

for i in range(n):
    if i==erase or  arr[i]==erase:
        continue
    if arr[i]==-1:
        root.append(i)
    
    edges[arr[i]].append(i)

que=root
ans=0

while que:
    cur=que.pop(0)
    if len(edges[cur])==0:
        ans+=1
    for i in edges[cur]:
        que.append(i)

print(ans)