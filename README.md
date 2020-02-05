# algorithm



### 자주 하는 실수





### 

### 학습내용:

## 2020년



### 2월 

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

