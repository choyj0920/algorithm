# baek5651 완전 중요한 간선- fail
import sys
from collections import deque
import itertools
input=sys.stdin.readline

f=[[0]*333 for _ in range(333)]
c=[[0]*333 for _ in range(333)]

g=[]*333
edge=[]
n,m=0,0

def init():
    global f
    global c
    f[:] = itertools.repeat(0, len(f))
    c[:] = itertools.repeat(0, len(c))
    for _ in range(333):
        g[_]=[]
    edge=[]

def addEdge(s, e, x):
    g[s].append(e) 
    c[s][e] += x
    g[e].append(s)
    edge.append((s, e));

def flow():
    par=[0]*333;
    while(1):
        par=[-1]*333
        q=deque()
        q.append(1)
        while len(q) :
            now = q.popleft()
            for nxt in g[now] :
                if par[nxt] == -1 and c[now][nxt] - f[now][nxt] > 0:
                    q.append(nxt)
                    par[nxt] = now

        if par[n] == -1:  
            break
        fl = 1e9+7
        i=n
        while i!= 1:
            a = par[i]
            b = i
            fl = min(fl, c[a][b] - f[a][b])
            i=par[i] 
		
        i=n
        while i!= 1:
            a = par[i]
            b = i
            f[a][b] += fl
            f[b][a] -= fl
            i=par[i] 
		
	


def solve():
    global n,m
    init() 
    n,m=map(int,input().split())
    for i in range(m):
        s, e, x=map(int,input().split())
        addEdge(s, e, x);
	
    flow();
    ans = 0;
    for s,t in edge:
        par=[-1]*333
        q=deque()
        q.append(s)
        while len(q) :
            now = q.popleft()
            for nxt in g[now]:
                if par[nxt] == -1 and c[now][nxt] - f[now][nxt] > 0 :
                    par[nxt] = now; 
                    q.append(nxt)
                
            

        if par[t] == -1: ans+=1
	
    print(ans)


t=int(input())
while t:
    t-=1
    solve()
