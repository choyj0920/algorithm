
///여기부터 복사 제출
#include <iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;


// 백준 11404번 플로이드


int main() {

}


// 백준 1865번 웜홀
/*
#define MAX_N 501
#define INF 987654321
int dist[MAX_N];
bool cycle = 0;
int N;
vector<pair<int, int>> v[MAX_N];

void bellmanFord(int vertex) {
	for (int i = 1; i <= vertex; i++) {
		//단순 반복 정점 j에 대한 갱신을 n^2 만큼 해주기 위해
		for (int j = 1; j <= vertex; j++) {
			for (auto it : v[j]) {
				if (dist[j] != INF && dist[it.first] > it.second + dist[j]) {
					if (i == vertex) 
						//마지막에도 relax가 갱신 되는 것은 음의 순환이 존재
						cycle = 1;
					dist[it.first] = dist[j] + it.second;
				}
			}
		}
	}
}
int main() {
	int TC;
	cin.tie(0); cin.sync_with_stdio(false);
	cin >> TC;
	int  M, W;
	int S, E, T;
	while (TC--) {
		cin >> N >> M >> W;
		fill(dist, dist + N + 1, INF);
		dist[1] = 0;
		cycle = 0;
		for (int i = 0; i <= N; i++) 
			v[i].clear();
		while (M--) {
			cin >> S >> E >> T;
			v[S].push_back({ E,T });
			v[E].push_back({ S,T });
		}
		while (W--) {
			cin >> S >> E >> T;
			v[S].push_back({ E,-T });
		}
		bellmanFord(N);
		cout << (cycle ? "YES" : "NO") << '\n';
	}
}
*/

// 백준 11657번 타임머신 
/*
#define MAX_N 501
#define MAX_M 6001
#define INF 987654321

int edge[MAX_N][MAX_N];
vector<pair<int, int> > adj[MAX_N];
void bellmanFord(int start, int vertex) {
	vector<int> upper(vertex + 1, INF);
	upper[start] = 0;
	bool update = false;
	
	for (int i = 1; i <= vertex; i++) {
		update = false;
		for (int j = 1; j <= vertex; j++) {
			//계속 업데이트
			if (upper[j] == INF) {
				//j가 업데이트 안됬으면 그냥 다음 반복으로
				continue;
			}
			for (int k = 0; k < adj[j].size(); k++) {
				//계속 업데이트 j와 연결되어 있는 
				int ver = adj[j][k].first;
				int cost = adj[j][k].second;
				if (upper[ver] > upper[j] + cost) {
					upper[ver] = upper[j] + cost;
					update = true;
				}
			}
		}
		if (!update)
			break;
	}
	if (update)
		cout << -1 << endl;
	else {
		for (int i = 2; i <= vertex; i++) {
			if (upper[i] == INF)
				cout << -1 << '\n';
			else
				cout << upper[i] << '\n';
		}
	}
}

int main() {
	int N, M;
	int A, B, C;
	cin.tie(0); cin.sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			edge[i][j] = INF;
		}
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		edge[A][B] = min(edge[A][B], C);
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (edge[i][j] < INF)
				adj[i].push_back({ j,edge[i][j] });
		}
	bellmanFord(1, N);
}
*/

// 백준 9370번 미확인 도착지 
/*



#define MAX_N 2001
#define MAX_M 50001
#define INF 987654321
typedef struct NODE {
	int end;
	int cost;
};

// 각 노드의 엣지를 저장하는 벡터 
// 0번 인덱스는 버린다. 
vector<NODE> EDGE_arr[MAX_N];
// 출발 노드에서부터의 거리를 저장하는 배열
int dist[MAX_N] = { 0 };
vector<int> dijkstra(int start, int vertex) {
	vector<int> dis(vertex + 1, INF);
	dis[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	que.push({ 0,start });

	while (!que.empty()) {
		int cost = que.top().first;
		int ver = que.top().second;
		que.pop();

		if (dis[ver] < cost)
			continue;

		for (int i = 0; i < EDGE_arr[ver].size(); i++) {
			int node = EDGE_arr[ver][i].end;
			int dis_to_node = cost + EDGE_arr[ver][i].cost;

			if (dis[node] > dis_to_node) {
				dis[node] = dis_to_node;
				que.push({ dis_to_node,node });
			}
		}
	}
	return dis;
}

int main() {
	int n, m, t, s, g, h;
	int dest[101] = { 0, };
	cin.tie(0); cin.sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		int a, b, c;
		for (int i = 1; i <= n; i++) {
			EDGE_arr[i].clear();
		}
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			EDGE_arr[a].push_back(NODE{ b, c });
			EDGE_arr[b].push_back(NODE{ a, c });
		}
		for (int i = 0; i < t; i++) {
			cin >> dest[i];
		}
		vector<int>from_s_dis = dijkstra(s, n);
		vector<int>from_g_dis = dijkstra(g, n);
		vector<int>from_h_dis = dijkstra(h, n);
		vector<int>result;
		for (int i = 0; i < t; i++) {
			int dis_dest = from_s_dis[dest[i]];
			if (dis_dest == from_s_dis[g] + from_g_dis[h] + from_h_dis[dest[i]] ||
				dis_dest == from_s_dis[h] + from_h_dis[g] + from_g_dis[dest[i]])
				result.push_back(dest[i]);
		}
		sort(result.begin(), result.end());

		for (auto it : result) {
			cout << it << ' ';
		}
		cout << '\n';
	}
	

}
*/


// 백준 1504번 특정한 최단경로 
/*
#define MAX_N 801
#define MAX_E 200001
#define INF 987654321
typedef struct NODE {
	int end;
	int cost;
};

// 각 노드의 엣지를 저장하는 벡터 
// 0번 인덱스는 버린다. 
vector<NODE> EDGE_arr[MAX_E];
// 출발 노드에서부터의 거리를 저장하는 배열
int dist[MAX_N] = { 0 };
int N, E;
vector<int> dijkstra(int start,int vertex) {
	vector<int> dis(vertex + 1, INF);
	dis[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	que.push({ 0,start });

	while (!que.empty()) {
		int cost = que.top().first;
		int ver = que.top().second;
		que.pop();

		if (dis[ver] < cost)
			continue;

		for (int i = 0; i < EDGE_arr[ver].size(); i++) {
			int node = EDGE_arr[ver][i].end;
			int dis_to_node = cost + EDGE_arr[ver][i].cost;

			if (dis[node] > dis_to_node) {
				dis[node] = dis_to_node;
				que.push({ dis_to_node,node });
			}
		}
	}
	return dis;
}

int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	cin >> N >> E;
	int a, b, c;
	int node1, node2;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		EDGE_arr[a].push_back(NODE{ b, c });
		EDGE_arr[b].push_back(NODE{ a, c });
	}
	cin >> node1 >> node2;
	vector<int>from_1_dis = dijkstra(1, N);
	vector<int>from_Node1_dis = dijkstra(node1, N);
	vector<int>from_Node2_dis = dijkstra(node2, N);
	int answer = min(from_1_dis[node1] + from_Node1_dis[node2] + from_Node2_dis[N],
		from_1_dis[node2] + from_Node2_dis[node1] + from_Node1_dis[N]);
	if (answer >= INF || answer < 0)
		cout << -1 << '\n';
	else
		cout << answer << '\n';

}
*/

// 백준 1753번 최단경로 
/*

#define INF 987654321
#define MAX_V 20001
#define MAX_E 300001

using namespace std;
int start_node_num, V, E;

typedef struct NODE {
	int end;
	int val;
};

// 각 노드의 엣지를 저장하는 벡터 
// 0번 인덱스는 버린다. 
vector<NODE> EDGE_arr[MAX_E];
// 출발 노드에서부터의 거리를 저장하는 배열
int dist[MAX_V] = { 0 };

void dijkstra() {
	priority_queue< pair<int, int> > pq;
	pq.push({ 0, start_node_num });

	// 노드의 거리 갱신은 V-1 번 만큼 하면 된다. 
	while (!pq.empty()) {
		int now_node = pq.top().second;
		int cost = -1 * pq.top().first;
		pq.pop();

		// 현재 노드에서 부터 주변에 있는 얘들의 값을 갱신한다. 
		for (int k = 0; k < EDGE_arr[now_node].size(); k++) {
			int new_val = dist[now_node] + EDGE_arr[now_node][k].val;
			int before_val = dist[EDGE_arr[now_node][k].end];

			// 현재 노드로 부터 연결된 엣지의 목적지까지 가는 거리와 기존의 거리를 비교하여, 
			// 기존의 것이 더 크면 값을 갱신한다.  
			if (new_val < before_val) {
				dist[EDGE_arr[now_node][k].end] = new_val;
				pq.push({ -1 * new_val, EDGE_arr[now_node][k].end });
			}
		}

	}
}

int main() {
	cin >> V >> E >> start_node_num;
	
	int from, to, val;
	// 간선 연결 
	for (int i = 0; i < E; i++) {
		cin >> from >> to >> val;
		EDGE_arr[from].push_back(NODE{ to, val });
	}

	// 간선간의 거리 초기화 
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}
	dist[start_node_num] = 0;

	
	dijkstra();

	// 값을 출력한다. 
	for (int i = 1; i <= V; i++) {
		if (dist[i] != INF) cout << dist[i] << '\n';
		else cout << "INF\n";
	}

	return 0;
}
*/

// 백준 2206번 벽 부수고 이동하기 
/*

int m, n;
int check4[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int arr[1001][1001] = { 0, };
int visit[1001][1001][2] = { 0, };
void bfs() {
	visit[1][1][0] = 1;
	queue<pair<int, pair<int, int>>> que;
	que.push(make_pair(0, make_pair(1, 1)));
	
	while (!que.empty()) {
		pair<int, int> k = que.front().second;
		int brokenwall = que.front().first;
		int cnt = visit[k.first][k.second][brokenwall];
		que.pop();
		for (int i = 0; i < 4; i++) {
			int a = k.first + check4[i][0];
			int b = k.second + check4[i][1];
			
			if (a > 0 && a <= n && b > 0 && b <= m) {
				if (arr[a][b] == 1 && brokenwall==0 &&!visit[a][b][1]) {
					visit[a][b][1] = cnt + 1;
					que.push(make_pair(1, make_pair(a, b)));
				}
				else if (arr[a][b] == 0 && visit[a][b][brokenwall] == 0) {
					visit[a][b][brokenwall] = cnt + 1;
					que.push(make_pair(brokenwall, make_pair(a, b)));
				}
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

	if (visit[n][m][0] == 0 && visit[n][m][1] == 0) {
		cout << -1 << '\n';
	}
	else if(visit[n][m][0]*visit[n][m][1]==0){
		cout << max(visit[n][m][0], visit[n][m][1]) << '\n';
	}
	else {
		cout << min(visit[n][m][0], visit[n][m][1]) << '\n';

	}

}*/

// 백준 1697번 숨바꼭질 
/*
int check3[3][2] = { {1,1},{-1,1},{0,2} };
int n, k, kmax;
int arr[200001] = { 0 };
void dfs() {
	queue<int>que;
	que.push(n);
	arr[n] = 1;
	while (!que.empty()) {
		int x = que.front();
		int _cnt = arr[x];
		que.pop();
		for (int i = 0; i < 3; i++) {
			int a = (x + check3[i][0]) * check3[i][1];
			if (a >= 0 && a <= kmax ) {
				if (arr[a] == 0) {
					arr[a] = _cnt + 1;
					que.push(a);
				}				
			}
		}
	}
}

int main() {
	cin >> n >> k;
	kmax = 100001;

	dfs();
	cout << arr[k] - 1 << '\n';
	
}
*/
// 백준 7569번 토마토 
/*

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
*/

// 백준 7576번 토마토 
/*

int m, n, cnt;
int check4[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int arr[1001][1001] = { 0, };
queue < pair<int, int>> que;
int found, total = 0;
void bfs() {
	int days = 0;
	int size;
	pair<int, int> k;
	while (!que.empty()) {
		size = que.size();
		total += size;
		if (total == n * m) {
			cout << days << '\n';
			break;
		}
		for (int j = 0; j < size; j++) {
			k = que.front();
			que.pop();

			for (int i = 0; i < 4; i++) {
				int a = k.first + check4[i][0];
				int b = k.second + check4[i][1];
				if (a >= 0 && a < n && b >= 0 && b < m && arr[a][b] == 0) {
					arr[a][b] = 1;
					que.push(make_pair(a, b));
				}
			}
		}
		days++;
	}
	if (total != n * m)
		cout << "-1" << '\n';

}

int main() {
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				que.push(make_pair(i, j));
			else if (arr[i][j] == -1)
				total++;
		}
	}
	bfs();

}
*/

// 백준 2178번 미로 탐색 
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

// 백준 1012번 유기농 배추 
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

// 백준 2667번 단지번호 붙이기
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

// 백준 2606번 바이러스
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

// 백준 1260번 DFS와 BFS 
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

// 백준 2618번 경찰차 
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


// 백준 10942번 팰린드롬? 
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


// 백준 7579번 앱 어려워 잘모르겠다 
/*
int memory[100], cost[100];
int dp[100][10001];//[i][비요ㅕㅇ]= 확보되는 메모리
int n, m;
int finddp(int index, int totalcost) {
	if (index >= n) {
		return 0;
	}
	
	int& result = dp[index][totalcost];
	if (result != 0) {
		return result;
	}
	result = finddp(index + 1, totalcost); //해당앱 비활 x
	
	if (cost[index] <= totalcost) {//이번 비용이 이전까지 쓴 비용보다 작은 경우
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

// 백준 1520번 내리막 길--dp가아닌 느낌으로 ..
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

// 백준 11049번 행렬 곱셈 순서 
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

// 백준 11066번 파일 합치기 
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

// 백준 2293번 동전1
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

// 백준 1655번 가운데를 말해요 
/*
priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;
int main() {
	// 구니까 그냥 pq 두개를 활용해서 하나의 1~n의 배열을 
	// 1~k까지는 top이 최대 값인 pq1에  
	// k~n까지는 top이 최소 값인 pq2에 넣게하여, pq1의 모든 원소는 pq2의 탑보다 작음
	//+ k는 n/2로 유지, 그리 하여 중간 값을 계속 추적 가능하게 설정
	
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

// 백준 11286번 절댓값 힙 
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

// 백준 1927번 최소힙 
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

// 백준 11279번 최대힙 
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


// 백준 12015번 가장 긴 증가하는 부분 수열 2 
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
		else {//이 부분 추가 여지두는 그런 //참고로 이부분이 이진 탐색
			auto low = lower_bound(v.begin(), v.end(), num);
			*low = num;
		}
	}
	cout << cnt;
}
*/

// 백준 1300번 k번쨰 수 
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

// 백준 2110번 공유기 설치
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
// 백준 2805번 나무 자르기 
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