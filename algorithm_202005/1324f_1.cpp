#include <iostream>
#include<vector>
#include <Algorithm>
using namespace std;

vector<int> a;
vector<int> dp;
vector<int> ans;
vector<vector<int>> g;

void dfs(int v, int p = -1) {
	dp[v] = a[v];
	for (auto to : g[v]) {
		if (to == p) continue;
		dfs(to, v);
		dp[v] += max(dp[to], 0);
	}
}

void dfs2(int v, int p = -1) {
	ans[v] = dp[v];
	for (auto to : g[v]) {
		if (to == p) continue;
		dp[v] -= max(0, dp[to]); //밑부분 제거하고
		dp[to] += max(0, dp[v]); // 밑부분 계산에 위부분을 지나는 부분 더해줌
		dfs2(to, v);
		dp[to] -= max(0, dp[v]); //종료후 값 원래대로
		dp[v] += max(0, dp[to]); //값 원래 대로
	}
}

int main() {


	int n;
	cin >> n;
	a = dp = ans = vector<int>(n);
	g = vector<vector<int>>(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == 0) a[i] = -1;
	}
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(0);
	dfs2(0);
	for (auto it : ans) cout << it << " ";
	cout << endl;

	return 0;
}