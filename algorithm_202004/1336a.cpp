#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
vector<int> edges[200005];
bool visit[200005];

class node {
public :
	int cnt, dist;
	bool operator<(const node& a) const {
		return dist - cnt < a.dist - a.cnt;
	}
}solv[200005];

int dfs(int pos) {
	int k = edges[pos].size();
	int count = 0;
	visit[pos] = true;

	for (int i = 0; i < k; i++) {
		if (!visit[edges[pos][i]]) {
			solv[edges[pos][i]].dist = solv[pos].dist + 1;
			count += dfs(edges[pos][i]);
		}
	}
	solv[pos].cnt = count;
	return count + 1;
}

int main() {
	cin.tie(0); cin.sync_with_stdio(false);

	ll ans = 0;
	int n, k, a, b;

	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	solv[1].dist = 0;
	dfs(1);
	sort(solv + 1, solv + n + 1);
	for (int i = n; i > n - k; i--)
		ans += solv[i].dist - solv[i].cnt;


	cout << ans << '\n';
}