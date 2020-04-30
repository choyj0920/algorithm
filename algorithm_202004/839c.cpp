#include <iostream>
#include<cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;
vector<int> edges[100005];
bool visit[100005];
double result;
void dfs(int po,int dep, double posi) {
	
	int cnt = 0;
	visit[po] = true;
	for (int i = 0; i < edges[po].size(); i++) {
		if (!visit[edges[po][i]])
			cnt++;
	}
	for (int i = 0; i < edges[po].size(); i++) {
		if (!visit[edges[po][i]]) {
			dfs(edges[po][i], dep + 1, posi / cnt);
		}
	}
	if (cnt == 0)
		result += (dep * posi);
}

int main() {
	
	int n;
	cin >> n;
	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);

	}
	dfs(1, 0, 1);
	
	printf("%.10lf", result);

	
}