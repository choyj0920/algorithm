# algorithm



### 자주 하는 실수

 



### 

### 학습내용:

## 2020년



### 2월 

Dynamic Programming; DP

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



#### 약수 구할때

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

    