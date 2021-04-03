# baek1182 부분수열
import sys
input=sys.stdin.readline
n,s=map(int,input().split())
arr=list(map(int,input().split()))
ans=0
def dfs(node,cnt,value):
    global ans
    if node>=n:
        if(cnt !=0 and value==s):
            ans+=1
        return
    dfs(node+1,cnt,value)
    dfs(node+1,cnt+1,value+arr[node])
dfs(0,0,0)
print(ans)

    
