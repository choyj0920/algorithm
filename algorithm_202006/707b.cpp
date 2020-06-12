#include <iostream>
#include <cstdio>
#include<vector>
#include <algorithm>
#include<string>
#define MAX_VALUE 100005
using namespace std;
typedef  long long  ll;
vector<pair<int,int>>edge[MAX_VALUE];
bool isStore[MAX_VALUE];
int n, m, k;


int main() {
	int u, v, l;
	int i, j;
	cin >> n >> m >> k;
	for (i = 1; i <= m; i++) {
		cin >> u >> v >> l;
		edge[u].push_back({ v,l });
		edge[v].push_back({ u,l });
		
	}
	vector<int> stores = vector<int>();
	for (i = 1; i <= k; i++) {
		cin >> u;
		isStore[u] = true;
		stores.push_back(u);
	}
	int _min;
	bool find = false;
	for (int v : stores) {
		for (i = 0; i < edge[v].size(); i++) {
			if (isStore[edge[v][i].first] == false) {
				if (find) {
					_min = ((_min < edge[v][i].second) ? _min : edge[v][i].second);
				}
				else {
					find = true;
					_min = edge[v][i].second;
				}
			}
		}
	}
	


	if (find)
		cout << _min << '\n';
	else
		cout << -1 << '\n';

}