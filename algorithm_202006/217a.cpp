#include <iostream>
#include <cstdio>
#include<vector>
#include <algorithm>
#include<string>
#define MAX_VALUE 1005
using namespace std;
typedef  long long  ll;
vector<int>edge[105];
int X[MAX_VALUE], Y[MAX_VALUE];
bool Visit[MAX_VALUE];
int n;

int dfs(int pos) {
	int i, k;
	k = edge[pos].size();
	Visit[pos] = true;
	for (i = 0; i < k;  i++) {
		if (!Visit[edge[pos][i]]) {
			dfs(edge[pos][i]);
		}
	}
	return 1;

}
int main() {
	int x, y;
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> X[i] >> Y[i];
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j < i; j++) {
			if (X[i] == X[j] || Y[i] == Y[j]) {
				edge[i].push_back(j);
				edge[j].push_back(i);
			}
		}
	}
	int ans = 0;
	
	for (i = 1; i <= n; i++) {
		if (Visit[i] == 0) {
			ans++;
			dfs(i);
		}
	}
	

	cout << ans - 1;
	
}