# algorithm


## 목차 

[자주 하는 실수](#자주-하는-실수)

[학습내용](#학습내용:)

[2020](#2020년)

[Dynamic Programming; DP](#Dynamic-Programming;-DP)

[약수 구할 때](#약수-구할때)

[벨만 포드 알고리즘, 다익스트라 알고리즘](#벨만-포드-알고리즘,-다익트라알고리즘)

[플로이드 와샬 알고리즘](#플로이드-와샬-알고리즘)

[트리의 지름 (임의의 두 노드 중 가장 먼 노드 길이)](#트리의-지름 (임의의-두-노드-중-가장-먼-노드-길이))

[Union-find (합집합 찾기)](#Union_find-(합집합-찾기))













# 자주 하는 실수

- ###  dp 문제에서 경로를 기록해야할때 

  - 새로 기록하는 dp에 이전경로 전체를 포함하는 경로가 아닌... 바로 이전 위치만을 표기하는 것이 보통 더 좋다.  출력할때 는 역추적하여 출력하면 됨
  
- 



# 학습내용:

## 2020년



### Dynamic Programming; DP

특정 범위까지의 값을 구하기 위해서 그것과 다른 범위까지의 값을 이용하여 효율적으로 값을 구하는 [알고리즘](https://namu.wiki/w/알고리즘) 설계 기법이다.

조금 장난스럽게 말해서 답을 재활용하는 거다. 앞에서 구했던 답을 뒤에서도 이용하고, 옆에서도 이용하고...엄밀히 말해 동적 계획법은 구체적인 알고리즘이라기보다는 문제해결 패러다임에 가깝다. 동적 계획법은 "어떤 문제를 풀기 위해 그 문제를 더 작은 문제의 연장선으로 생각하고, 과거에 구한 해를 활용하는" 방식의 알고리즘을 총칭한다. 

DP알고리즘- LIS알고리즘(+LCS)알고리즘

 

```cpp
#include<vector>
//LIS알고리즘
int main() {
	vector<int> v;
	int N; //N수열 갯수
	cin >> N;
	int k;
	for (int i = 0; i < N; i++) {
		cin >> k; //수열을 하나씩
		auto it = lower_bound(v.begin(), v.end(), k);
        // 알맞은 자리 찾기
			*it = k;
	}
	cout << v.size() << '\n';	
}
//LCS 알고리즘
for (int i = 1; i <= len1; i++) {
		
		for (int j = 1; j <= len2; j++) {
			if (str1[i - 1] != str2[j - 1]) {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
			else {
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
		}
	}
	cout << DP[len1][len2] << '\n';




```

이차원 배열 , 배열을 이용해서 이전값,과 계속 비교해서 최적의 값을 찾는 DP



### 약수 구할때

- ```cpp
  vector<int> v;
  for(int i=1; i<=n ;i++){
      if(n % i ==0)
          v.push_back(i);
  } //이런 식으로 구하는 것 보다
  for (int i = 2; i * i <= g; i++)
  		if (!(g % i)) {
  			ans.push_back(i);
  			if (i != g / i) ans.push_back(g / i);
  		}//이렇게 하고 필요하면 sort로 정렬하는것이 한참 빠르다
  
  ```

- 유클리드 호제법 - 두 수의 최대 공약수 구하기

  - ```cpp
    int gcd(int a, int b)
    {
    	return b ? gcd(b, a%b) : a;
    }
    
    int gcd(int a, int b)
    {
        int c;
    	while(b)
    	{
    		c = a % b;
    		a = b;
    		b = c;
    	}
        return a;
    }
    
    ```

    

이항정리

페르마 소정리

피보나치수 피사노주기(피보나치수의 어떠한 수에 나머지는 일정주기가 있음 생각해 보면 당연한 것 )

p(n)= abc,p(n+1)=abc+1 일때 

p(n*자연수+ i )%abc= p(i)% abc= p(i) 일것.



### 벨만 포드 알고리즘, 다익트라알고리즘

- #### 다익트라 알고리즘

  - 매번 방문하지 않은 노드 중에서 최단 거리가 가장 짧은 노드를 선택합니다.
  - 음수 간선이 없다면 최적의 해를 찾을 수 있습니다.

- #### 벨만 포드 알고리즘

  - 매번 모든 간선을 전부 확인합니다.
    -  따라서 다익스트라 알고리즘에서의 최적의 해를 항상 포함합니다. 시간복잡도는 더 높음 
  - 다익스트라 알고리즘에 비해서 시간이 오래 걸리지만 음수 간선 순환을 탐지 할 수 있습니다.



```python

import sys
input =sys.stdin.readline
INF= int(1e9)  #무한을 의미하는 값으로 10억을 설정

def bf(start):
    # 시작 노드에 대해서 초기화
    dist[start]=0
    # 전체 n번의 라운드(round)를 반복
    for i in range(n):
        # 매 반복마다 "모든 간선"을 확인하며
        for j in range(m):
            cur=edges[j][0]
            next_node= edges[j][1]
            cost= edges[j][2]
            # 현재 간선을 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if dist[cur] != INF and dist[next_node] > dist[cur] +cost:
                dist[next_node]=dist[cur]+cost
                # n 번째 라운드에서도 값이 갱신 된다면 음수 순환이 존재
                if i== n - 1:
                    return True
    return False

# 노드의  개수, 간선의 개수 입력받기
n,m=map(int, input().split())
# 모든 간선에 대한 정보를 담는 리스트 만들기
edges= []
# 최단 거리 테이블을 모두 무한으로 초기화
dist=[INF] * (n + 1)

# 모든 간선 정보를 입력 받기 
for _ in range(m):
    a, b, c = map(int, input().split())
    # a번 노드에서 b번 노드로 가는 비용이 c라는 의미
    edges.append((a,b,c))
    
# 벨만 포드 알고리즘을 수행
negative_cycle = bf(1) # 1번 노드가 시작노드
if negative_cycle:
    print("-1")
else:
    # 1번 노드를 제외한 다른 모든 노드로 가기 위한 최단 거리 출력
    for i in range(2,n+1):
        # 도달할 수 없는 경우, -1을 출력
        if dist[i] ==INF:
            print("-1")
       	# 도달할 수 있는 경우 거리를 출력
        else:
            print(dist[i])
         
```



### 플로이드 와샬 알고리즘

모든 정점에서 다른 모든 정점으로의 최단경로를 찾는 알고리즘

 이차원 배열로 각 정점에서 각정점으로가는 최단거리 초기화 후, 각 정점을 지난다고 가정하여  반복문

**코드**

```python
# 백준 11404 플로이드

import sys
input =sys.stdin.readline
INF= int(1e9)  #무한을 의미하는 값으로 10억을 설정

def floydWarshall():
    # k = 거쳐가는 노드
    for k in range(1,n+1):
        # i= 출발 노드
        for i in range(1,n+1):
            # j = 도착 노드
            for j in range(1,n+1):
                if edges[i][k]+edges[k][j] <edges[i][j]:
                    edges[i][j]= edges[i][k]+edges[k][j] 

# 노드의 개수, 간선의 개수 입력
n= int(input())
m= int(input())
# 경로 배열 
edges=[[INF]*(n+1) for _ in range(n+1)]

for _ in range(m): #같은 노선 다른 경로 존재
    a,b,c=map(int,input().split())
    edges[a][b]=min(edges[a][b],c)
for i in range(1,n+1): # 같은 노드 끼리 0
    edges[i][i]=0

floydWarshall() 

# 값 출력
for i in range(1,n+1):
    for j in range(1,n+1):
        if edges[i][j] !=INF:
            print(edges[i][j],end=' ')
        else:
            print(0,end=' ')
    print()
```



### 다시 상기시키는 다익스트라(+경로)

```python
# baek11779 최소비용 구하기2 

import sys

input=sys.stdin.readline

n=int(input())
m=int(input())

INF =int(1e9)

# 입력 ,변수 초기화
edges=[[INF for i in range(n+1)]for _ in range(n+1)]
for _ in range(m):
    a,b,c= map(int,input().split())
    edges[a][b]= min(c,edges[a][b])     # 경로가 같은데 비용이 다른 것 있다는 언급이 없었지만 생각했어야..
start_city,end_city=map(int,input().split())

costs=[INF for i in range(n+1)]         # 다익스트라 start_city에서의 거리 배열
parents=[0 for i in range(n+1)]         # 경로 추적용 이전위치
visitied=[False for i in range(n+1)]

def find_lowest_cost_node(costs):       # 다익스트라 최단거리 찾는 함수
    lowest_cost=INF
    lowest_cost_node=None
    for node in range(len(costs)):
        cost= costs[node]
        if cost<lowest_cost and visitied[node]==False:
            lowest_cost=cost
            lowest_cost_node=node
    return lowest_cost_node    

# 다익스트라
node = start_city
costs[start_city]=0
visitied[start_city]=True
while node is not None:
    cost= costs[node]
    neighbors=edges[node]
    for i in range(len(neighbors)):
        new_cost=cost+neighbors[i]
        if costs[i]> new_cost: # 현재 가지고 있는 cost보다 최단 거리 라면
            costs[i]=new_cost
            parents[i]=node
    visitied[node]=True
    node = find_lowest_cost_node(costs)

print(costs[end_city])

trace=[]
current=end_city
while current != start_city:
    trace.append(current)
    current=parents[current]
trace.append(start_city)
trace.reverse()
print(len(trace))
for i in trace:
    print(i,end=' ')


```



### 트리의 지름 (임의의 두 노드 중 가장 먼 노드 길이)

```python
# baek1167 트리의 지름
# 트리의 지름을 구하는 방법은 정해져있다. 
# 먼저 임의의 정점부터 모든 정점까지의 거리를 구하여 
# 가장 먼 거리를 가진 정점을 구한다. 
# 그 후에 그 정점으로부터 모든 정점까지의 거리를 다시 구해서 
# 그 거리들 중 가장 먼 값이 트리의 지름이 된다.

import sys
input=sys.stdin.readline
# input
v = int(input())

# variable init
edge=[[] for _ in range(v+1)]
visited=[False for _ in range(v+1)]

maxIndex=0          # 최대 값 index
maxDistance=0       # 최대 값

def dfs(node ,cost):        #dfs함수
    global maxDistance
    global maxIndex
    if visited[node] != False:  #첫 방문 시에만 진행
        return
    
    if maxDistance < cost:  # 최대값 설정
        maxDistance = cost
        maxIndex =node
    
    visited[node] =True        # 방문 설정

    for next,dis in edge[node]: # 연결된 노드 dfs
        dfs(next,cost+dis)

    
# input
for i in range(1,v+1):      
    temp=input().split()
    for j in range(1,len(temp)-1,+2):
        edge[i].append([int(temp[j]),int(temp[j+1])])


# 임의의 노드(1)에서 dfs(bfs)수행 후 
dfs(1,0)
# 가장 먼 노드에서 다시 dfs(bfs)수행 하면
for _ in range(v+1): visited[_]=False
dfs(maxIndex,0)
# 이때 나온 최장 거리가 트리의 지름
print(maxDistance)

```



### 파이썬의 재귀함수최대는 1000

재귀함수를 사용할 때 ,맞는 거 같은데  이상하게 런타임 에러가 발생할 때는 sys.setrecursionlimit(10**9) 

을 이용해 재귀함수 제한을 늘려서 시도



### Union_find (합집합 찾기)

재귀를 이용하여  - 이것도 재귀 깊이 제한을 늘려야한다

```python
# baek1717 집합의 표현

import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)

n,m=map(int,input().split())
arr=[-1 for _ in range(n+1)]
parent=[_ for _ in range(n+1)]

def getParent(parent,x):    # 부모 노드를 찾는 함수
    if parent[x]==x : return x
    parent[x]=getParent(parent,parent[x])
    return parent[x]


def unionParent(parent,a,b):# 두 부모 노드를 합치는 함수
    a= getParent(parent,a)
    b= getParent(parent,b)
    if a<b: parent[b]=a
    else : parent[a]=b

def checkUnion(parent,a,b): # 두 노드가 같은 부모노드를 가지는지 확인하는 함수
    a= getParent(parent, a)
    b= getParent(parent, b)
    if a==b: return True
    return False

for _ in range(m):
    check,a,b=map(int,input().split())
    if check==0:
        unionParent(parent,a,b)
    elif check ==1:
        if checkUnion(parent,a,b):
            print("YES")
        else:
            print("NO")

```



### 크루스칼 알고리즘

가장 가중치가 낮은 간선부터 정렬하여 union find를 사용하여 연결되어 있지 않은 집합끼리  간선 연결, 모든 정점이 연결되면 종료

```python
# baek1197 최소 스패닝 트리
from collections import deque
import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)

# union-find 함수들
def getParent(parent,x):    # 부모 노드를 찾는 함수
    if parent[x]==x : return x
    parent[x]=getParent(parent,parent[x])
    return parent[x]


def unionParent(parent,a,b):# 두 부모 노드를 합치는 함수
    a= getParent(parent,a)
    b= getParent(parent,b)
    if a<b: parent[b]=a
    else : parent[a]=b

def checkUnion(parent,a,b): # 두 노드가 같은 부모노드를 가지는지 확인하는 함수
    a= getParent(parent, a)
    b= getParent(parent, b)
    if a==b: return True
    return False
# union-find 함수들

# input
v,e=map(int,input().split())
parent=[ _ for _ in range(v)]
edges=[]
for _ in range(e):
    a,b,c=map(int, input().split())
    edges.append([c,a-1,b-1])

edges=sorted(edges) # 정렬 후

cnt= 0              # 현재 연결된 정점 갯수 확인을 위한
total_weight=0      # 최소 가중치 합 
for weight,a,b in edges:    # 정렬된 간선으로 반복문
    if not checkUnion(parent,a,b):  # 현재 간선의 두 정점이 연결되어 있지 않으면
        total_weight+=weight        # 최소 가중치 합에 포함
        cnt+=1
        unionParent(parent,a,b)     # 연결되었음을 union-find 기법으로
        if cnt>=v-1:                # 모두 연결되엇으면-종료
            break

print(total_weight)         # 결과 출력

```



### KMP(knuth-Morris-Pratt)

문자열 매칭 알고리즘 

반복되는 연산을 얼마나 줄일 수 있는지 판별 

-접두사와 접미사가 일치하는 최대 길이를 찾는것!

| 길이 | 문자열   | 최대 일치 길이 |
| ---- | -------- | -------------- |
| 1    | a        | 0              |
| 2    | ab       | 0              |
| 3    | aba      | 1              |
| 4    | abac     | 0              |
| 5    | abaca    | 1              |
| 8    | abacaaba | 3              |

접두사 접미사를 구하면  일치하는경우에 점프를 수행 할 수있다는 점에서 효율적

```python
def makeTable(pattern):
    patternSize=len(pattern)
	arr =[0 for _ in range(patternSize)]
    j=0
    for i in range(patternSize):
        while(j>0 and pattern[i] != pattern[j]):
            j=table[j-1]
        if pattern[i]==pattern[j]:
            j+=1
            table[i]= j
    return table
    
    
```

 최종 코드

```python
# baek1786 찾기
import sys
# readline 쓰면 뒤에 엔터 떼줘야 해서 기본 input 사용

def makeTable(pattern):  # 접두 접미 겹치는거 찾는 함수
    patternSize=len(pattern)
    table = [0  for _ in range(patternSize)]
    j=0
    for i in range(1,patternSize):  # 
        while j>0 and pattern[i] != pattern[j]:
            j=table[j-1]
        if pattern[i]==pattern[j]:
            j+=1
            table[i]= j
    return table
# input
T=str(input())
P=str(input())
lenT=len(T)
lenP=len(P)
# 테이블
table=makeTable(P)
answer=[]

# KMP 구문
j =0
for i in range(lenT):           # T 문장 처음부터 끝까지 비교
    while j>0 and T[i] != P[j]: # 앞에 한자리 이상 같고 이번자리가 다를 떄
        j= table[j-1]           # j를 0에서 겹치는 부분만큼 jump해서 다시 비교
    if T[i] == P[j]:        # 일치하면
        if j== lenP-1:      # P와 전부 일치하면 
            j= table[j]     # 다음 체크에 Jump
            answer.append(i-lenP+2) # 값 기록
        else:
            j+=1
# 출력
print(len(answer))
print(*answer)

```

또한 반복되는 문자열 찾기에도 사용가능



### Trie 

탐색속도에 특화된 알고리즘으로 저장공간을 더 사용하지만 일반 문자열에서 탐색보다 빠르다

```python
# baek14725 trie 풀이 
import sys
input= sys.stdin.readline

class Node:
    def __init__(self,key):
        self.key=key
        self.child=dict()

class Trie:
    def __init__(self):
        self.head=Node(None)

    def insert(self, word):
        cur =self.head

        for ch in word:
            if ch not in cur.child:
                cur.child[ch]=Node(ch)
            cur = cur.child[ch]
        cur.child['*']=True

def print_trie(l,cur):
    if '*' in cur.child:
        return
    sorted_child=sorted(cur.child)
    
    for c in sorted_child:
        print("--"*l, end='')
        print(c)
        print_trie(l+1,cur.child[c])
    
trie=Trie()

for _ in range(int(input())):
    foods = input().split()
    k= int(foods.pop(0))

    trie.insert(foods)

cur =trie.head
print_trie(0,cur)

```

### 

### Sparse Table-희소 테이블

- 어떤 작업(예제에서는, 앞으로 한 칸 가기)을 여러 번 반복해야 할 때, 이를 빠르게 처리할 수 있게 해 줍니다.
- 하나의 값을 채우기 위해서, table을 두 번 연속으로 참조하는 과정이 들어갑니다.
- 정점이나 원소의 개수(N)뿐만 아니라, 반복할 횟수(K)가 시간·공간복잡도에 들어갑니다.
  만약 이 K가 20, 30 하는 정도로 굉장히 작다면 sparse table의 크기도 굉장히 작아지고, 사실 쓸 필요가 없을 수도 있습니다.
  반대로 K가 굉장히 커져서 2^64까지도 간다면 sparse table의 크기도 커집니다. ***"어차피 log를 붙이면 64배밖에 안 되는 거 아냐?"\*** 하고 생각하실 지도 모르지만, N=500,000 (50만)인 경우에 (64·N)짜리 int 배열의 크기는 122 MiB나 됩니다. 메모리 제한이 빡빡하다면 어려울 지도 몰라요.
- 기록 대상을 미리 알고 있어야 하며, 중간에 바뀌면 안 됩니다. 예를 들어 한 화살표가 바뀌면, 그로 인해 배열 전체를 갈아엎고 새로 계산해야 할 지도 모릅니다. 그러면 전처리(preprocessing)를 해놓은 의미가 없죠.

```python
# baek17435 합성함수와 쿼리

import sys
import math
input=sys.stdin.readline

m=int(input())
arr= [0]+list(map(int,input().split()))
MAXLOG2=int(math.log2(500002) +1)
sparseTable= [[0 for col in range(m+1)] for row in range(MAXLOG2)]

for i in range(1,m+1):
    sparseTable[0][i]=arr[i]


for i in range(1,MAXLOG2):
    for j in range(1,m+1):
        sparseTable[i][j]=sparseTable[i-1][sparseTable[i-1][j]]


q= int(input())
for _ in range(q):
    n,x=map(int,input().split())
    cur=x
    for i in range(MAXLOG2,-1,-1):
        if n & (1<<i):
            cur=sparseTable[i][cur] # 2^i 만큼 이동
    print(cur)
	
```



### 최소 공통조상 LCA 문제 

중복되는 값들의 연산을 희소테이블로 

```python
# baek11438 LCA2

import sys
from math import log2
from collections import deque
input=sys.stdin.readline

n=int(input())
logN=int(log2(n)+1)
tree =[[] for _ in range(n+1)] # 각노드의 연결 노드
for _ in range(n-1):
    a,b=map(int,input().split())
    tree[a].append(b)
    tree[b].append(a)

p_list=[0 for _ in range(n+1)]  # 부모노드 저장
depth=[0 for _ in range(n+1)]   # 부모노드 개수

visited=[False for _ in range(n+1)] # dfs 방문

q=deque()
q.append(1) # 루트
while q:
    p=q.popleft()
    visited[p] =True
    for i in tree[p]:
        if not visited[i]:
            q.append(i)
            p_list[i]=p
            depth[i]=depth[p]+1

# 2^k 번쨰 부모노드 저장
# log2 1000000 
dp=[[0 for _ in range(logN)] for i in range(n+1)] # dp[a][b] a의 2^b 번째 부모노드

for i in range(n+1):
    dp[i][0]=p_list[i]

for j in range(1,logN): # 희소 테이블 설정
    for i in range(1,n+1):
        dp[i][j]=dp[dp[i][j-1]][j-1]

m= int(input())
for _ in range(m):
    a,b=map(int,input().split())
    if depth[a]>depth[b]:
        a,b=b,a
    # 둘의 레벨 차이
    dif =depth[b]-depth[a]
    for i in range(logN):
        if dif&(1<<i):
            b=dp[b][i]
            
    if a==b:    # 같으면 출력
        print(a)
        continue
    for i in range(logN-1,-1,-1): # 루트 부터 내려가다가 처음달라지는 순간 노드의
        if dp[a][i] != dp[b][i]:
            a=dp[a][i]
            b=dp[b][i]
    print(dp[b][0])     # 바로 부모노드가 정답

```

위에랑 비슷한데 복잡해져서인지 계속 틀리고 실수하고   - 한달뒤 풀어보자 (2020.12.30)

```python
# baek3176 도로 네트워크

import sys
from math import log2
from collections import deque
input=sys.stdin.readline

n=int(input())
logN=int(log2(n)+1)
tree =[[] for _ in range(n+1)] # 각노드의 연결 노드
for _ in range(n-1):
    a,b,c=map(int,input().split())
    tree[a].append([b,c])
    tree[b].append([a,c])

p_list=[[0,0] for _ in range(n+1)]  # 부모노드 저장
depth=[0 for _ in range(n+1)]   # 부모노드 개수

visited=[False for _ in range(n+1)] # dfs 방문

q=deque()
q.append(1) # 루트
visited[1] =True
while q:
    p=q.popleft()
    for i,d in tree[p]:
        if not visited[i]:
            q.append(i)
            p_list[i][0]=p
            p_list[i][1]=d
            visited[i] = True
            depth[i]=depth[p]+1

# 2^k 번쨰 부모노드 저장
# log2 1000000 
dp=[[[0,0,0] for _ in range(logN)] for i in range(n+1)] 
# dp[a][b] =[a의 2^b 번째 부모노드,a부터 그 부모노드까지의 최소도로,최장 도로]

for i in range(n+1):    # 
    dp[i][0][0]=p_list[i][0]
    dp[i][0][1]=p_list[i][1]
    dp[i][0][2]=p_list[i][1]


for j in range(1,logN): # 희소 테이블 설정
    for i in range(1,n+1):
        dp[i][j][0]=dp[dp[i][j-1][0]][j-1][0]
        dp[i][j][1]=min(dp[i][j-1][1],dp[dp[i][j-1][0]][j-1][1])
        dp[i][j][2]=max(dp[i][j-1][2],dp[dp[i][j-1][0]][j-1][2])

m= int(input())
for _ in range(m):
    a,b=map(int,input().split())
    if depth[a]>depth[b]:
        a,b=b,a
    # 둘의 레벨 차이
    dif =depth[b]-depth[a]
    shortest = 1000000
    longest = 0
    for i in range(logN):
        if dif&(1<<i):
            shortest=min(shortest,dp[b][i][1])
            longest=max(longest,dp[b][i][2])
            b=dp[b][i][0]
            
    if a==b:    # 같으면 출력
        print(shortest,longest)
        continue
    
    for i in range(logN-1,-1,-1): # 루트 부터 내려가다가 처음달라지는 순간 노드의
        if dp[a][i][0] != dp[b][i][0] and dp[a][i][0] != 0 and dp[b][i][0] !=0:
            shortest=min(shortest,dp[a][i][1],dp[b][i][1])
            longest=max(longest,dp[a][i][2],dp[b][i][2])
            a=dp[a][i][0]
            b=dp[b][i][0]
            
    # 경로에 최소 공통조상밑의 경로까지 포함
    shortest=min(shortest,dp[a][0][1],dp[b][0][1])
    longest=max(longest,dp[a][0][2],dp[b][0][2])


    print(shortest,longest)# 결과
```

### 강한 결합요소 Strongly Connected Component 

방향그래프에서 서로에게 갈 수 있는 정점들을 찾는 알고리즘

-타잔 알고리즘: dfs를 정점마다 써서  체크



```python
# baek2150 Strongly Connected Component
import sys
from collections import deque
input=sys.stdin.readline
sys.setrecursionlimit(10**9)

v,e =map(int,input().split())
edges=[[] for _ in range(v+1)]
for _ in range(e):
    a,b = map(int, input().split() )
    edges[a].append(b)
    
visited=[0 for _ in range(v+1)]
finished=[False for _ in range(v+1)]

stack=[]
id = 0
SCC=[]
def dfs(node ):
    global id
    id += 1
    visited[node]= id  # node 별 dfs 순서 정의를 위해  0이면 아직 미 방문
    stack.append(node) # 스택에 삽입 - 같은 강한결합요소 체크를 위해
    parent =visited[node]
    for next in edges[node]:
        # 아직 방문하지 않았다면, dfs 수행 
        if visited[next] ==0: parent=min(parent, dfs(next))
        # 현재 dfs가 수행중인--> 부모일수도 아니면 형제일수도 
        elif not finished[next]: parent =min(parent,visited[next])
    
    # 부모 노드가 자기 자신인 경우
    if parent==visited[node]:
        scc=[]
        while True:
            t=stack.pop()
            scc.append(t)
            finished[t]=True
            if t==node: break
        scc=sorted(scc)
        SCC.append(scc)

    # 부모 출력
    return parent

for i in range(1,v+1):
    if not visited[i]: dfs(i)
SCC=sorted(SCC)
print(len(SCC))
for i in range(len(SCC)):
    print(*SCC[i],end=' -1\n')
   
```



### 강한 결합요소 2-SAT 

충족 가능성 문제 여러개의 boolean 변수들로 이루어진 boolean expression 가 있을 때 각 변수의 값을 true false로 설정하여 전체 식의 결과를 true로 만들 수 있는지 판별하는 문제 ,

- a v b 명제 일 때  ~a-> b, ~b ->a 인 것을 이용하여 이것을 그래프의 엣지로 만들어 강한 결합요소 묶음으로 만들어 묶음안에 a, ~a 등의 모순되는 것이 없으면 가능하다는 풀이

```cpp
// baek11280 2-SAT -3 
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
const int MAX = 10001;  // n변수 최대 값

int N,M, cnt,scc,dfsn[MAX*2],sccidx[MAX*2];
vector<int> edge[MAX*2];
bool finished[MAX*2];
stack<int> st;

// 자신의 not literal의 정점 번호 리턴 +,- 전환
inline int oppo(int n) {return n%2? n-1:n+1;}

int findscc(int cur)
{
   dfsn[cur] = ++cnt;
   int ret= dfsn[cur];
   st.push(cur);

   for(auto next : edge[cur])
   {
       if(dfsn[next] == 0) // 아직 방문 x
       {
           ret= min(ret,findscc(next));
       }
       else if(!finished[next]) // 
       {
           ret = min(ret,dfsn[next]);
       }
   }    

   if(ret >= dfsn[cur] && !finished[cur])
   {
       while(1)
       {
           int stop = st.top();
           st.pop();
           sccidx[stop] = scc;
           finished[stop] = true;
           if(stop == cur) break;
       }
       scc++;
   }

   return ret;
}
int main(){
    //input
    scanf("%d %d",&N,&M);
    for (int i =0; i<M;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        a = (a<0? -(a+1)*2 : a*2-1);
        b = (b<0? -(b+1)*2 : b*2-1);
        edge[oppo(a)].push_back(b);
        edge[oppo(b)].push_back(a);        
    }

    // scc
    for (int i=0; i<N*2;i++){
        if (dfsn[i]==0) findscc(i);
    }

    for (int i =0;i<N;i++){
        if (sccidx[i*2]==sccidx[i*2+1]){    //불 가능
            puts("0");
            return 0;
        }
    }

    // 간응
    puts("1");


}
```

### 세그먼트 트리

```python
# baek11505 구간 곱 구하기
import sys
from math import *
input=sys.stdin.readline

# update
def update(node, start, end, idx, val): # 세그먼트 트리 업데이트 함수
    if idx < start or end < idx: # 범위를 벗어났으면 종료
        return

    if start == end:  # 마지막 노드 
        tree[node] = val
        return

    mid = (start + end) // 2
    update(node*2,start,mid,idx,val) # 현재노드의 좌측 업데이트
    update(node*2+1,mid+1,end,idx,val) # 현재노드의 우측 업데이트
    tree[node] = (tree[node*2] * tree[node*2+1]) % 1000000007  # 좌측 노드* 우측노드

# query
def query(node, start, end, left, right): # 노드 곱 쿼리
    if right < start or end < left: # 없는 자리면, 곱셈의 항등원 1리턴
        return 1

    if left <= start and end <= right: # 노드의 아래가 모두 포함 되면 전체 포함
        return tree[node]

    mid = (start + end) // 2
    tmp = query(node*2,start,mid,left,right) * query(node*2+1,mid+1,end,left,right) # 좌측 우측 노드 곱 (포함 범위만)
    return tmp % 1000000007        # 나머지만 리턴

# main
n, m, k = [int(x) for x in input().split()]

h = int(ceil(log2(n)))
t_size = 1 << (h+1)

arr = []
tree = [0] * t_size

for i in range(n):
    num = int(input())
    arr.append(num)
    update(1,0,n-1,i,num)

for _ in range(m+k):
    a, b, c = [int(x) for x in input().split()]

    if a == 1:  # 노드 값 변경
        arr[b-1] = c
        update(1,0,n-1,b-1,c)
    elif a == 2: # 노드들 곱 쿼리
        print(query(1,0,n-1,b-1,c-1))
```

