#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

int dp[100005][2]; //[0]자기가 작은 값, [1] 자기가 큰값
int arr[100005];

int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1][1] = dp[1][0] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i][1] = 1;
		if (arr[i - 1] + 1 == arr[i]) {
			dp[i][1] = dp[i - 1][0] + 1;
		}
		else if (arr[i - 1] == arr[i]) {
			dp[i][0] = dp[i - 1][0] + 1;
			dp[i][1] = dp[i - 1][1] + 1;
		}
		else if (arr[i - 1] - 1 == arr[i]) {
			dp[i][0] = dp[i - 1][1] + 1;
		}



	}
	int maxlen = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i][0] > maxlen)
			maxlen = dp[i][0];
		if (dp[i][1] > maxlen)
			maxlen = dp[i][1];
	}
	
	cout << maxlen << '\n';
}