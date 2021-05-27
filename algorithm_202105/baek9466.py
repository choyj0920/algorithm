# baek9466 텀 프로젝트
import sys
sys.setrecursionlimit(999999)
input=sys.stdin.readline
def dfs(node):
    global ans
    visited[node]=True
    team.append(node)
    num=arr[node]

    if visited[num]:
        if num in team:
            ans+= team[team.index(num):]
        return 
    else:
        dfs(num)
        
for t in range(int(input())):
    n=int(input())
    arr=[0]+list(map(int,input().split()))
    visited=[True]+[False]*(n)
    ans=[]
    for i in range(1,n+1):
        if visited[i] is False:
            team=[]
            dfs(i)
    print(n-len(ans))


    