#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

typedef long long ll;
ll a[100005];
ll dp[100005][2]; //0은 그점수 얻음, 1는 안 얻음

int n,max_num;

using namespace std;

void solution() {
	
	if (a[1]) {
		dp[1][0] = a[1];
		
	}
	for (int i = 2; i <= max_num; i++) {
		if (a[i]) {
			dp[i][0] = dp[i - 1][1] + (i * a[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]);
		}
		else {
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]);
			dp[i][0] = -1000;
		}
	}

	return;

}

int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	cin >> n;
	max_num = 0;
	int temp;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		max_num = max(max_num, temp);
		a[temp]++;
	}
	solution();
	cout << max(dp[max_num][0], dp[max_num][1]) << '\n';

	

}