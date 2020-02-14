
///������� ���� ����
#include <iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

// ���� 7576�� �丶��

int m, n,h, cnt;
int check4[6][3] = { {0,1,0},{0,-1,0},{1,0,0},{-1,0,0},{0,0,-1},{0,0,1} };
int arr[101][101][101] = { 0, };
queue < pair<int, pair<int, int>>> que;
int found, total = 0;
void bfs() {
	int days = 0;
	int size;
	pair<int,pair<int,int>> k;
	while (!que.empty()) {
		size = que.size();
		total += size;
		if (total == n * m*h) {
			cout << days << '\n';
			break;
		}
		for (int j = 0; j < size; j++) {
			k = que.front();
			que.pop();

			for (int i = 0; i < 6; i++) {
				int a = k.first + check4[i][0];
				int b = k.second.first + check4[i][1];
				int c = k.second.second + check4[i][2];
				if (a >= 0 && a < n && b >= 0 && b < m &&c>=0&&c<h&& arr[a][b][c] == 0) {
					arr[a][b][c] = 1;
					que.push(make_pair(a, make_pair(b, c)));
				}
			}
		}
		days++;
	}
	if (total != n * m * h)
		cout << "-1" << '\n';

}

int main() {
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1)
					que.push(make_pair(i, make_pair(j, k)));
				else if (arr[i][j][k] == -1)
					total++;
			}
		}
	}
	
	bfs();

}


// ���� 2178�� �̷� Ž�� 
/*

int n, m, arr[101][101] = { 0, };
int check4[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void bfs() {
	int cnt = 2;
	queue < pair<int, int>> que;
	que.push(make_pair(1, 1));
	arr[1][1] = cnt;

	while (!que.empty()) {
		pair<int,int> k= que.front();
		que.pop();
		int _cnt = arr[k.first][k.second];
		for (int i = 0; i < 4; i++) {
			int a = k.first + check4[i][0];
			int b = k.second + check4[i][1];
			if (a >= 1 && a <= n && b >= 1 && b <= m && arr[a][b] == 1) {
				arr[a][b] = _cnt + 1;
				que.push(pair<int, int>(a,b));
			}
		}
	}
}

int main() {
	cin >> n >> m;
	char c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c;
			arr[i][j] = (c == '1' ? 1 : 0);
		}
	}
	bfs();
	cout << arr[n][m] - 1 << '\n';


}
*/

// ���� 1012�� ����� ���� 
/*
#include <cstring>
int arr[51][51];
int n,m;
int T;
int k;
int check4[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
void dfs(int a, int b, int cnt) {
	arr[a][b] = cnt;
	
	for (int i = 0; i < 4; i++) {
		int r = a + check4[i][0];
		int c = b + check4[i][1];

		if (r >= 1 && r <= n && c >= 1 && c <= m && arr[r][c] == 1) {
			dfs(r, c, cnt);
		}
	}
}


int main() {
	
	cin >> T;
	
	while (T--) {
		cin >> m >> n >> k;
		int a, b;
		int cnt = 0;
		memset(arr, 0, 51 * 51);

		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			arr[b+1][a+1] = 1;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] == 1) {
					cnt++;
					dfs(i, j, cnt + 1);
				}
			}
		}
		cout << cnt << '\n';
	}
		
}*/

// ���� 2667�� ������ȣ ���̱�
/*
int danjicnt[400] = { 0, }, arr[26][26];
int n;
int cnt;

int check4[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
void dfs(int a, int b, int cnt) {
	arr[a][b] = cnt;
	danjicnt[cnt - 2]++;
	for (int i = 0; i < 4; i++) {
		int r = a + check4[i][0];
		int c = b + check4[i][1]; 

		if (r >= 1 && r <= n && c >= 1 && c <= n && arr[r][c] == 1) {
			dfs(r, c, cnt);
		}
	}
}


int main() {
	cin >> n;
	char c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c;
			arr[i][j] = (c == '1' ? 1 : 0);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 1) {
				cnt++;
				dfs(i, j, cnt + 1);
			}
		}
	}
	sort(danjicnt, danjicnt + cnt);
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) {
		cout << danjicnt[i] << '\n';
	}
}*/

// ���� 2606�� ���̷���
/*

int visit[101] = { 0, }, mat[101][101] = { 0, };
int n, m, v;
int result;
void dfs(int k) {
	visit[k] = 1;
	result++;
	for (int i = 1; i <= n; i++) {
		if (!visit[i] && mat[k][i])
			dfs(i);

	}
}
int main() {
	cin >> n >> m;
	int a, b;
	result = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		mat[a][b] = mat[b][a] = 1;
	}
	dfs(1);
	cout << result - 1 << '\n';
}
*/

// ���� 1260�� DFS�� BFS 
/*

int visit[1001] = { 0, }, mat[1001][1001] = { 0, };
int n, m, v;
void dfs(int k) {
	cout << k << ' ';
	visit[k] = 1;
	for (int i = 1; i <= n; i++) {
		if (!visit[i] && mat[k][i])
			dfs(i);
		
	}
}

void bfs(int k) {
	queue<int> que;
	que.push(k);
	visit[k] = 0;
	while (!que.empty()) {
		k = que.front();
		cout << k << ' ';
		que.pop();
		for (int i = 1; i <= n; i++) {
			if (visit[i] && mat[i][k]) {
				que.push(i);
				visit[i] = 0;
			}
		}
	}
}
int main() {
	cin >> n >> m >> v;
	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		mat[a][b] = mat[b][a] = 1;
	}
	dfs(v);
	cout << '\n';
	bfs(v);
}*/

// ���� 2618�� ������ 
/*
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int n, w;
struct col {
	int x, y;
	int operator-(const col& aa) {
		return abs(x - aa.x) + abs(y - aa.y);
	}
};
col fir[1001], sec[1001];
int dp[1001][1001];

int func(int c1, int c2) {
	if (c1 == w || c2 == w)
		return 0;

	int& ref = dp[c1][c2];
	if (ref != -1)
		return ref;

	int np = max(c1, c2) + 1;
	int n1 = fir[c1] - fir[np];
	int n2 = func(np, c2) + n1;

	int m1 = sec[c2] - sec[np];
	int m2 = func(c1, np) + m1;

	return ref = min(n2, m2);
}

vector<int> v;
void tracking(int c1, int c2) {
	if (c1 == w || c2 == w)
		return;

	int np = max(c1, c2) + 1;
	int n1 = fir[c1] - fir[np];
	int n2 = dp[np][c2] + n1;

	int m1 = sec[c2] - sec[np];
	int m2 = dp[c1][np] + m1;

	if (n2 > m2) {
		v.push_back(2);
		tracking(c1, np);
	}
	else {
		v.push_back(1);
		tracking(np, c2);
	}
}

int main() {
	cin.tie(0); cin.sync_with_stdio(false);

	cin >> n >> w;

	fir[0] = { 1,1 };
	sec[0] = { n,n };
	for (int i = 1; i <= w; ++i) {
		cin >> fir[i].x >> fir[i].y;
		sec[i] = { fir[i].x, fir[i].y };
	}

	memset(dp, -1, sizeof(dp));
	cout << func(0, 0) << '\n';

	tracking(0, 0);
	for (auto a : v)
		cout << a << '\n';


	return 0;
}*/


// ���� 10942�� �Ӹ����? 
/*
int arr[2001];
bool dp[2001][2001];
int n, m;
int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i][i] = true;
	}
	for (int i = 1; i <= n - 1; i++) {
		dp[i][i + 1] = dp[i + 1][i] = (arr[i] == arr[i + 1]);
	}
	for (int i = 2; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			dp[j][j + i] = dp[j + i][j] = (arr[j] == arr[j + i] && dp[j + 1][j + i - 1]);
		}
	}
	cin >> m;
	int s, e;
	while (m--) {
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}
}*/


// ���� 7579�� �� ����� �߸𸣰ڴ� 
/*
int memory[100], cost[100];
int dp[100][10001];//[i][���Ť�]= Ȯ���Ǵ� �޸�
int n, m;
int finddp(int index, int totalcost) {
	if (index >= n) {
		return 0;
	}
	
	int& result = dp[index][totalcost];
	if (result != 0) {
		return result;
	}
	result = finddp(index + 1, totalcost); //�ش�� ��Ȱ x
	
	if (cost[index] <= totalcost) {//�̹� ����� �������� �� ��뺸�� ���� ���
		result = max(result, memory[index] + finddp(index + 1, totalcost - cost[index]));
	}
	return result;
}

int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> memory[i];
	for (int i = 0; i < n; i++)
		cin >> cost[i];
	int totalCost = 0;
	while (1) {
		if (finddp(0, totalCost) >= m)
		{
			cout << totalCost << endl;
			break;
		}
		totalCost++;
	}

}*/

// ���� 1520�� ������ ��--dp���ƴ� �������� ..
/*
int arr[501][501];
int dp[501][501] = { 0, };
int m, n;

void setdp(const int& i,const int& j) {
	if (i > 0 && arr[i][j] < arr[i - 1][j])
		dp[i][j] += dp[i - 1][j];
	if (i < m - 1 && arr[i][j] < arr[i + 1][j])
		dp[i][j] += dp[i + 1][j];
	if (j > 0 && arr[i][j] < arr[i][j - 1])
		dp[i][j] += dp[i][j - 1];
	if (j < n - 1 && arr[i][j] < arr[i][j + 1])
		dp[i][j] += dp[i][j + 1];
	return;
}
int main() {
	cin.tie(0); cin.sync_with_stdio(false);

	cin >> m >> n;
	vector < pair<int, pair<int, int>>> v;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			v.push_back(make_pair(arr[i][j], make_pair(i, j)));
		}
	}
	dp[0][0] = 1;
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (auto it : v) {
		setdp(it.second.first, it.second.second);
	}
	cout << dp[m - 1][n - 1];
}
*/

// ���� 11049�� ��� ���� ���� 
/*
int arr[501][2] = { 0, };
int dp[501][501];
int find_dp(int i, int j) {
	if (i == j)
		return 0;
	if (dp[i][j] != 0) return dp[i][j];

	for (int k = i; k < j; k++) {
		int temp = find_dp(i, k) + find_dp(k + 1, j) + arr[i][0] * arr[k][1] * arr[j][1];
		if (dp[i][j] == 0 || dp[i][j] > temp)
			dp[i][j] = temp;
	}
	return dp[i][j];
}

int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	cout << find_dp(1, N) << "\n";
}*/

// ���� 11066�� ���� ��ġ�� 
/*
#include <cstring>
int arr[501] = { 0, };
int sum[501];
int dp[501][501];

int find_dp(int i, int j) {
	if (i == j)
		return 0;
	if (dp[i][j] != -1) return dp[i][j];
	
	for (int k = i; k < j; k++) {
		int temp = find_dp(i, k) + find_dp(k + 1, j) + sum[j] - sum[i - 1];
		if (dp[i][j] == -1 || dp[i][j] > temp)
			dp[i][j] = temp;
	}
	return dp[i][j];
}
int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	int tastT, k; 
	cin >> tastT;
	while (tastT--) {
		memset(dp, -1, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		int N;
		cin >> N;

		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}
		cout << find_dp(1, N) << "\n";
	}
}*/

// ���� 2293�� ����1
/*
#define MAX_KINDS 100
#define MAX_VALUE 100000
int coin[MAX_KINDS] = { 0 , };
int dp[10001] = { 0, };
int main() {
	int n, k;
	cin.tie(0); cin.sync_with_stdio(false);
	cin >> n >> k;
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - coin[i] >= 0) {
				dp[j] += dp[j - coin[i]];
			}
		}
	}
	cout << dp[k] << '\n';
}
*/

// ���� 1655�� ����� ���ؿ� 
/*
priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;
int main() {
	// ���ϱ� �׳� pq �ΰ��� Ȱ���ؼ� �ϳ��� 1~n�� �迭�� 
	// 1~k������ top�� �ִ� ���� pq1��  
	// k~n������ top�� �ּ� ���� pq2�� �ְ��Ͽ�, pq1�� ��� ���Ҵ� pq2�� ž���� ����
	//+ k�� n/2�� ����, �׸� �Ͽ� �߰� ���� ��� ���� �����ϰ� ����
	
	cin.tie(0); cin.sync_with_stdio(false);
	
	int n;
	cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (pq1.empty() || pq1.top() >= num) {
			pq1.push(num);
			if (pq1.size() > pq2.size() + 1) {
				pq2.push(pq1.top());
				pq1.pop();
			}
		}
		else if (pq2.empty() || pq2.top() <= num) {
			pq2.push(num);
			if (pq2.size() > pq1.size()) {
				pq1.push(pq2.top());
				pq2.pop();
			}
		}
		else if (pq1.size() <= pq2.size()) {
			pq1.push(num);
		}
		else if (pq1.size() > pq2.size()) {
			pq2.push(num);
		}
		cout << pq1.top() << '\n';
	}

}*/

// ���� 11286�� ���� �� 
/*
struct absolute_INT
{
	absolute_INT(const int& x) :x(x) {

	}
	int x;
	bool operator<(const absolute_INT& aa) const {
		if ((x > 0 ? x : -x) == (aa.x > 0 ? aa.x : -aa.x)) {
			return x > aa.x;
		}
		return  (x > 0 ? x : -x) > (aa.x > 0 ? aa.x : -aa.x);
	}
};

ostream& operator<<(ostream& out, const absolute_INT& aa) {
	out << aa.x;
	return out;
}

int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	int n;
	cin >> n;
	priority_queue<absolute_INT> pq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			if (pq.empty())
				cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}

		}
		else {
			pq.push(num);
		}
	}
}
*/

// ���� 1927�� �ּ��� 
/*
#include<queue>
int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	int n;
	cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			if (pq.empty())
				cout << 0 << '\n';
			else {
				cout << -pq.top() << '\n';
				pq.pop();
			}

		}
		else {
			pq.push(-num);
		}
	}
}*/

// ���� 11279�� �ִ��� 
/*
#include<queue>
int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	int n;
	cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			if (pq.empty())
				cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}

		}
		else {
			pq.push(num);
		}
	}
	
}*/


// ���� 12015�� ���� �� �����ϴ� �κ� ���� 2 
/*

int main() {
	int n;
	cin.tie(0); cin.sync_with_stdio(false);
	cin >> n;
	vector<int >v;
	v.push_back(0);
	int num;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num > v.back()) {
			v.push_back(num);
			cnt++;
		}
		else {//�� �κ� �߰� �����δ� �׷� //����� �̺κ��� ���� Ž��
			auto low = lower_bound(v.begin(), v.end(), num);
			*low = num;
		}
	}
	cout << cnt;
}
*/

// ���� 1300�� k���� �� 
/*
int main() {
	int n, k;
	cin.tie(0);
	cin >> n >> k;
	
	int left = 1, last = k;
	int result = -1;
	while(left<=last){
		int cnt = 0;
		int mid = (left + last) / 2;
		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n);

		}
		if (cnt < k) {
			left = mid + 1;
		}
		else {
			result = mid;
			last = mid - 1;
		}
	}
	cout << result << '\n';
}*/

// ���� 2110�� ������ ��ġ
/*
int main() {
	int n, c;
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> n >> c;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	int left = 1, last = v[n - 1] - v[0];
	int d = 0;
	int ans = 0;
	while (left <= last) {
		int mid = (left + last) / 2;
		int start = v[0];
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			d = v[i] - start;
			if (mid <= d) {
				++cnt;
				start = v[i];
			}
		}
		if (cnt >= c) {
			ans = mid;
			left = mid + 1;
		}
		else {
			last = mid - 1;
		}
	}
	cout << ans << '\n';
}
*/
// ���� 2805�� ���� �ڸ��� 
/*

bool possible(const long long& n, const long long& m, const long long& h,
	const vector<long long>&v) {

	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		long long k = v[i] - h;
		if (k > 0)
			cnt += k;
	}
	return (cnt >= m ? true : false);
}
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<long long> v(n);
	long long first = 1, last = 0, result = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		last = max(v[i], last);
	}
	while (first <= last) {
		long long mid = (first + last) / 2;
		if (possible(n, m, mid, v)) {
			result = max(mid, result);
			first = mid + 1;
		}
		else {
			last = mid - 1;
		}

	}
	cout << result << '\n';
	
}
*/