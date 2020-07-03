#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<string, vector<string>> adj;
map<string, bool> vis;
int n;

int dfs(string s) {
	if (vis[s])
		return 0;

	int dist = 0;
	vis[s] = true;

	for (int i = 0; i < adj[s].size(); i++) {
		dist = max(dfs(adj[s][i]), dist);
	}
	
	return dist + 1;
}

int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	cin >> n;
	string aa, bb;
	for (int i = 0; i < n; i++) {
		cin >> aa >> bb >> bb;

		transform(aa.begin(), aa.end(), aa.begin(), ::tolower);
		transform(bb.begin(), bb.end(), bb.begin(), ::tolower);

		adj[aa].push_back(bb);
		adj[bb].push_back(aa);
	}
	
	cout << dfs("polycarp");



}

