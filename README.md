# algorithm


## 목차 

[자주 하는 실수](#자주-하는-실수)

[학습내용](#학습내용:)

[2020](#2020년)

[Dynamic Programming; DP](#Dynamic-Programming;-DP)

[약수 구할 때](#약수-구할때)

[벨만 포드 알고리즘, 다익스트라 알고리즘](#벨만-포드-알고리즘,-다익트라알고리즘)

[플로이드 와샬 알고리즘](#플로이드-와샬-알고리즘)















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













