#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int dp[4001];
int n, a, b, c;
int k[3];
void dp_process() {
	for (int i = 0; i < n; i++) {
		if (dp[i]) {
			for (int j = 0; j < 3; j++) {
				if ((i + k[j]) <= n)
					dp[i + k[j]] = dp[i] + 1;
			}
		}
	}
}

int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	cin >> n >> k[0] >> k[1] >> k[2];
	dp[0] = 1;
	sort(k, k + 3);
	dp_process();
	cout << dp[n] - 1 << '\n';
	

}
