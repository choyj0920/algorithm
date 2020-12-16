# algorithm


## 목차 

[자주하는 실수](#자주-하는-실수)

[학습내용](#학습내용:)

[2020](#2020년)

[Dynamic Programming; DP](#Dynamic-Programming;-DP)

[약수 구할 때](#약수-구할때)

[벨만 포드 알고리즘, 다익스트라 알고리즘](#벨만-포드-알고리즘,-다익트라알고리즘)















### 자주 하는 실수

 



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


