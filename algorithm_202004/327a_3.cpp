
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;
int n;
int p[101];
int dp[101][3];
//[0] 이전에 플립이미했을 때 지금꺼는 플립x, [1] 이번꺼 까지 플립 되있음, [2]아직 플립이 일어나지 않음
int find_3() {
	int answer = 0;
	dp[0][0] = dp[0][1] = -1001;
	for (int i = 1; i <= n; i++) {
		
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + p[i];
		
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]) + (1 - p[i]);

		dp[i][2] = dp[i - 1][2] + p[i];

	}
	answer = max(dp[n][0], dp[n][1]);
	if (n == 1)
		answer = dp[n][1];

	return answer;
}

int main() {
	cin.tie(0); cin.sync_with_stdio(false);

	cin >> n;
	int temp;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];

	}
	cout << find_3() << '\n';


}

