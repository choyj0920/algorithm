#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;
int n;
int dp[100];

int find_1() {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int cnt = 0;
			for (int k = 0; k < n; k++) {
				if (k >= i && k <= j) {
					if (dp[k] == 0)
						cnt++;

				}
				else {
					if (dp[k] == 1)
						cnt++;
				}
			}
			if (answer < cnt)
				answer = cnt;

		}
	}
	

	return answer;
}

int main() {
	cin.tie(0); cin.sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> dp[i];
	cout << find_1() << '\n';


}

