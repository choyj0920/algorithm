#include <iostream>
#include<vector>
#include <Algorithm>
using namespace std;

vector<int> a;
vector<int> dp;
vector<int> ans;
vector<vector<pair<int,bool>>> g;

void dfs(int v, int p = -1) {
	
	for (auto to : g[v]) {
		if (to.first == p) continue;		
		dfs(to.first, v);
		dp[v] += dp[to.first];
		if (!to.second)
			dp[v] += 1;
	}
}

void dfs2(int v, int p = -1) {
	ans[v] = dp[v];
	for (auto to : g[v]) {
		if (to.first == p) continue;
		dp[to.first] = ans[v] + (to.second ? 1 : -1);		
		dfs2(to.first, v);

	}
}

int main() {


	int n;
	cin >> n;
	dp=ans = vector<int>(n);
	g = vector<vector<pair<int,bool>>>(n);
	
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back({ y, 1 });
		g[y].push_back({ x, 0 });
	}
	int _min = n;
	
	dfs(0);
	dfs2(0);
	for (int i = 0; i < n; i++) {
		_min = min(_min, ans[i]);
	}
	cout << _min << '\n';
	for (int i = 0; i < n; i++) {
		if (ans[i] == _min)
			cout << i + 1 << ' ';
	}
	cout << '\n';
	return 0;
}