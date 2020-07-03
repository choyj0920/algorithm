#include <iostream>
#include<vector>

using namespace std;

vector<int> Edges[200005];
vector<int> fromCh[200005];
bool visit[200005];
int DownMax[200005];

class node {
public:
	int bw, upMax, fromP,ans;
}a[200005];

int dfs(int pos) {
	
	int thisChild;
	int i, k; k = Edges[pos].size();
	visit[pos] = true;
	a[pos].upMax = 0;
	for (i = 0; i < k; i++) {
		if (!visit[Edges[pos][i]]) {
			thisChild = dfs(Edges[pos][i]);
			fromCh[pos][i] = thisChild;
			if (thisChild != -1)
				a[pos].upMax += thisChild;

		}
	}
	if (a[pos].bw) a[pos].upMax++;
	else a[pos].upMax--;
	return a[pos].upMax;
}

int dfs2(int pos,int fP) {
	int i, k; k = Edges[pos].size();
	visit[pos] = true;

	if (fP != -1) a[pos].ans = a[pos].upMax + fP;
	else a[pos].ans = a[pos].upMax;
	for (i = 0; i < k; i++) {
		if (!visit[Edges[pos][i]]) {
			if (fromCh[pos][i] == -1) dfs2(Edges[pos][i], a[pos].ans);
			else dfs2(Edges[pos][i], a[pos].ans - fromCh[pos][i]);
			

		}
	}
	return 0;
}

int main() {
	int n;
	cin >> n;
	int p, q;
	for (int i = 1; i <= n; i++) cin >> a[i].bw;
	for (int i = 1; i < n; i++) {
		cin >> p >> q;
		Edges[p].push_back(q);
		Edges[q].push_back(p);
		fromCh[p].push_back(0);
		fromCh[q].push_back(0);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) visit[i] = 0;
	dfs2(1, 0);


	for (int i = 1; i <= n; i++) cout << a[i].ans << ' ';
	cout << '\n';
}