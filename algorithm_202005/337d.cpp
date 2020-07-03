#include <iostream>
#include<vector>
#include <Algorithm>
#include<string>
using namespace std;

vector<int> dp;
vector<int> ans;
vector<int> msett;
vector<vector<int>> g;

int n, m, d;
void dfs(int v, int cnt, int p = -1) {
	for (auto to : g[v]) {
		if (to == p) continue;
		if (cnt <= 0)
			return;
		dfs(to, cnt - 1, v);
		ans[to]++;
		
	}
	
}

void dfs2(int v, int p = -1) {
	
}

int main() {
	cin >> n >> m >> d;

	msett = vector<int>();
	dp = ans = vector<int>(n);
	g = vector<vector<int>>(n);
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x;
		x--;
		msett.push_back(x);
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	for (int i = 0; i < msett.size(); i++) {
		ans[msett[i]]++;
		dfs(msett[i], d);
	}
	bool check = false;
	for (int i = n-1; i >=0; i--) {
		if (ans[i] == m) {
			cout << i + 1 << '\n';
			check = true;
			break;
		}
	}
	if (!check)
		cout << 0 << '\n';

	
	return 0;
}