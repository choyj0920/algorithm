#include <iostream>
#include <cstdio>
#include<vector>
#include <algorithm>
#include<string>
#include <limits.h>
#define MAX_VALUE 100005
#define MAX_DISTANCE 99999;
using namespace std;
typedef  long long  ll;
vector<pair<int, int>>edge[MAX_VALUE];
bool visit[MAX_VALUE];

int n, m, k;
ll dijk[100005];

int main() {
	int i, j;
	int a, b, w;
	int place, dis;

	

	//입력
	cin >> n >> m;


	for (i = 0; i < m; i++) {
		cin >> a >> b >> w;
		edge[a].push_back({ b,w });
		edge[b].push_back({ a,w });
		
	}
	for (int i = 2; i <= n; i++) {
		dijk[i] = -1;
	}
	for (int i = 0; i < edge[1].size(); i++) {
		dijk[edge[1][i].first] = edge[1][i].second;
	}
	
	visit[1] = true;
	//n-2번 반복
	for (i = 1; i < n-1; i++) {
		ll _min= MAX_DISTANCE;
		int _minindex = 1;
		for (j = 2; j <= n; j++) {
			if (dijk[j] != -1 && _min >= dijk[j] && visit[j] ==false) {
				_min = dijk[j];
				_minindex = j;
			}
		}
		visit[_minindex] = true;
		for (j = 0; j < edge[_minindex].size(); j++) {
			place = edge[_minindex][j].first;
			if (!visit[place]) {
				dis = edge[_minindex][j].second;
				if (dijk[place] == -1 || dijk[place] > (dis + _min)) {
					dijk[place] = dis + _min;
				}
			}

		}
	}

	for (i = 2; i <= n; i++) {
		if (dijk[i] == -1) {
			cout << -1 << " ";
		}
		else {
			cout << dijk[i] << " ";
		}
	}
	cout << '\n';

	


}