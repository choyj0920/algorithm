# algorithm



### 자주 하는 실수





### 

### 학습내용:

## 2020년



### 2월 

DP알고리즘- LIS알고리즘(+LCS)알고리즘

```cpp
#include<vector>
int main() {
	vector<int> v;
	int N; //N수열 갯수
	cin >> N;
	int k;
	for (int i = 0; i < N; i++) {
		cin >> k; //수열을 하나씩
		auto it = lower_bound(v.begin(), v.end(), k);
        //
			*it = k;
	}
	cout << v.size() << '\n';	
}






```

