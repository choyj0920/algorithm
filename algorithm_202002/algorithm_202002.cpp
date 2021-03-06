
//여기부터 복사 제출
	#include <iostream>
	#include<vector>
	#include<algorithm>
	using namespace std;


// 백준 1654번 랜선자르기 
/*
	int n, k;
	vector<long long>v(10001,0);
	bool possible(long long len) {
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += v[i] / len;

		}

		if (cnt >= n)
			return true;
		return false;
	}

	int main() {
		cin.sync_with_stdio(false);
		cin.tie(0);
		cin >> k >> n;
		long long max_sun = 0;
		for (int i = 0; i < k; i++) {
			cin >> v[i];
			max_sun = max(max_sun, v[i]);
		}
		long long result = 0, first = 1;
		while (first <= max_sun) {
			long long mid = (first + max_sun) / 2;
			if (possible(mid)) {
				result = max(result, mid);

				first = mid + 1;
			}
			else {
				max_sun = mid - 1;
			}
		
		}
		cout << result << '\n';
		
	}*/


// 백준 10816번 숫자 카드2
/*

	int main() {
		cin.sync_with_stdio(false);
		cin.tie(0);
		int n, m;
		cin >> n;
		vector<int>v(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		cin >> m;
		for (int i = 0; i < m; i++) {
			int num;
			cin >> num;
			cout << upper_bound(v.begin(), v.end(), num) - lower_bound(v.begin(), v.end(), num) << ' ';
		}
	}
	*/

// 백준 1920번 수찾기 
/*
	int arr[100001] = { 0, };
	void _Bsearch(int first, int last, int target) {
		int mid;
		while (last - first >= 0) {
			mid = (first + last) / 2;

			if (arr[mid] == target) {
				cout << "1\n";
				return;
			}
			else if (arr[mid] > target) {
				last = mid - 1;
			}
			else {
				first = mid + 1;
			}
		}
		cout << "0\n";
		return;
	}
	int main() {
		cin.tie(0); cout.tie(0);
		cin.sync_with_stdio(false);

		int n, m;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		cin >> m;
		int find;
		for (int i = 0; i < m; i++) {
			cin >> find;
			_Bsearch(0, n - 1, find);
		}
	}*/

// 백준 2261번 가장 가까운 두 잠 
/*
#include <vector>
#include <set>
#include <cmath>
	struct Point {
		int x, y;
		Point() {

		}
		Point(int x, int y) :x(x), y(y) {

		}
		bool operator<(const Point& p) const {
			if (y == p.y) {
				return x < p.x;
			}
			else {
				return y < p.y;
			}
		}
		int distance(const Point& p) const {
			return (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y);
		}
	};

	bool oper_x(const Point& a, const Point& b) {
		return a.x < b.x;
	}
	

	int main() {
		cin.tie(0);
		cin.sync_with_stdio(false);
		int n;
		Point p1, p2;
		cin >> n;
		vector<Point> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].x >> v[i].y;
		//x축 방향 기준으로 정렬
		sort(v.begin(), v.end(), oper_x);
		//아무런 거리 하나 잡아서
		int dis = v[0].distance(v[1]);
		set<Point> s; s.insert(v[0]), s.insert(v[1]);
		int start = 0;
		int x_diff;
		for (int i = 2; i < n; i++) {
			p1 = v[i]; //p1 
			while (start < i) {
				p2 = v[start];
				x_diff = p2.x - p1.x;
				if (x_diff * x_diff > dis) {
					//거리가 더 크면 그냥 버리기
					s.erase(p2);
					start++;
				}
				else
					break;
			}
			int d = (int)(sqrt((double)dis) + 1);
			auto up = s.upper_bound(Point(100000, p1.y + d));
			auto low = s.lower_bound(Point(-100000, p1.y - d));

			while (low != up) {
				int temp = p1.distance(*low);
				if (temp < dis)
					dis = temp;
				low++;
			}
			s.insert(p1);

		}
		cout << dis << '\n';
		
	}*/


// 백준 6549번 히스토그램에서 가장 큰 직사각형
/*
#include<stack>
	int arr[100001] = { 0, };
	int main() {
		
		int n;
		cin >> n;
		while (n) {
			for (int i = 0; i < n; i++) {
				cin >> arr[i];
			}
			stack<int> s;
			long long area = 0;
			for (int i = 0; i < n; i++) {
				long long left = i;
				while (!s.empty() && arr[s.top()] > arr[i]) {
					long long height = arr[s.top()];
					s.pop();
					long long width = i;
					if (!s.empty()) {
						width = (i - s.top() - 1);
					}
					if (area < width* height)
						area = width * height;

				}
				s.push(i);
			}
			while (!s.empty()) {
				long long height = arr[s.top()];
				s.pop();
				long long width = n;
				if (!s.empty()) {
					width = n - s.top() - 1;

				}
				if (area < width * height)
					area = width * height;
			}
			cout << area << '\n';
			cin >> n;
		}
	}*/

// 백준 2749번 피보나치수
/*
long long a[1500050];
int INF = 1000000;
void find() {
	a[0] = 0;
	a[1] = 1;
	for (int i = 0; i < 1500000; i++) {
		a[i + 2] = (a[i + 1] + a[i])%INF;
	
	}
	return;
}
int main() {
	find();
	long long n;
	cin >> n;
	cout << a[n % 1500000] << "\n";
}
*/
// 백준 10830번 행렬 제곱 
/*
#include <iostream>
using namespace std;
long long a[6][6], ans[6][6], c[6][6], n, b;
void cal(long long a[6][6], long long b[6][6])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= 1000;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = c[i][j];

}
int main() {
	cin >> n >> b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];

		}
		ans[i][i] = 1;
	}

	while (b > 0)
	{
		if (b % 2 == 1)//지수가 홀수면
		{
			cal(ans, a);
		}
		cal(a, a);
		b /= 2;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
}*/

// 백준 2740번 행렬 
/*
int mat1[101][101] = { 0, }, mat2[101][101] = { 0, };
int answer[101][101] = { 0, };
void cal_matrix(int n, int m, int k) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int cell = 0;
			for (int v = 0; v < m; v++) {
				cell += mat1[i][v] * mat2[v][j];
			}
			answer[i][j] = cell;
		}
	}
}
int main() {
	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat1[i][j];				
		}
	}
	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> mat2[i][j];
		}
	}
	cal_matrix(n, m, k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << answer[i][j] << ' ';
		}
		cout << '\n';
	}
}
*/


// 백준 11401번 이항계수 
/*
long long fac[4000001], n, k;
long long inv[4000001];//x!

#define MOD 1000000007
long long power(long long a, long long b) {
	long long result = 1;
	while (b > 0) {
		if (b % 2) {
			result *= a;
			result %= MOD;
		}
		a *= a;
		a %= MOD;
		b /= 2;
	}
	return result;
}


int main() {
	fac[1] = 1;
	for (int i = 2; i <= 4000000; i++) {
		//팩토리얼 구하기 
		fac[i] = (fac[i - 1] * i) % MOD;
	}
	//페르마의 소정리를 이용 fac의 inverse 구하기
	inv[4000000] = power(fac[4000000], MOD - 2);
	for (int i = 4000000 - 1; i > 0; i--) {
		inv[i] = (inv[i + 1] * (i + 1)) % MOD;
		
	}
	cin.tie(0);
	cin >> n >> k;
	if (n == k || !k) {
		cout << 1 << '\n';
	}
	else {
		long long result = (fac[n] * inv[n - k] % MOD);
		result = (result * inv[k]) % MOD;
		cout << result << '\n';
			
	}
	   
}*/

// 백준 1629번 곱셈 
/*

long long findpow(const int& a, const int& b,const int &c) {
	if (b == 1)
		return a % c;
	else {
		long long powofa = findpow(a, b / 2, c);
		if (b % 2)
			return (((powofa * powofa) % c) * a) % c;
		else
			return ((powofa * powofa) % c);
	}
}
int main() {
	
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	cout << findpow(a, b, c);
}
*/

// 백준 1780번 종이의 갯수 
/*
int arr[2200][2200] = { 0, };
int answer[3] = { 0, };
void find(int row, int col, int size) {
	if (size == 1) {
		answer[arr[row][col] + 1]++;
		return;
	}
	int k = arr[row][col];
	int check_di = false;
	int cellcount = size * size;
	for (int i = 1; i < cellcount; i++) {
		if (arr[row + (i / size)][col + (i % size)] != k) {
			check_di = true;
			break;
		}
	}
	if (check_di) {
		int per_size = size / 3;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				find(row + per_size *i, col + per_size *j, per_size);
			}
		}
	}
	else {
		answer[k + 1]++;
	}
}
int main() {
	int n;
	cin.tie(0);
	for (int i = 0; i < 3; i++) {
		answer[i] = 0;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	find(0, 0, n);
	for (int i = 0; i < 3; i++) {
		cout << answer[i] << '\n';
	}
}
*/
// 백준 1992번 쿼드트리
/*
int arr[64][64] = { 0, };
void find(int row, int col, int size) {
	if (size == 1) {
		cout << arr[row][col];
		return;
	}
	int k = arr[row][col];
	int check_di = false;
	int cellcount = size * size;
	for (int i = 1; i < cellcount; i++) {
		if (arr[row + (i / size)][col + (i % size)] != k) {
			check_di = true;
			break;
		}
	}
	if (check_di) {
		int half_size = size / 2;
		cout << '(';
		find(row, col, half_size);
		find(row, col + half_size, half_size);
		find(row + half_size, col, half_size);
		find(row + half_size, col + half_size, half_size);
		cout << ')';
	}
	else {
		cout << k;
	}
}

int main() {
	int n;
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char a;
			cin >> a;
			arr[i][j] = (a == '1' ? 1 : 0);
		}
	}
	find(0, 0, n);
}
*/

// 백준 2630번 색종이 만들기 
/*
int blue = 0, white = 0;
int arr[128][128] = { 0, };
void find(int row, int col, int size) {
	if (size==1) {
		arr[row][col] == 1 ? blue++ : white++;
		return;
	}
	int k = arr[row][col];
	int check_di = false;
	int cellcount = size * size;
	for (int i = 1; i < cellcount; i++) {
		if (arr[row + (i / size)][col + (i % size)] != k) {
			check_di = true;
			break;
		}
	}
	if (check_di) {
		int half_size = size / 2;
		find(row, col, half_size);
		find(row, col + half_size, half_size);
		find(row + half_size, col, half_size);
		find(row + half_size, col + half_size, half_size);
	}
	else {
		k == 1 ? (blue++) : (white++);
	}
}
int main() {
	int n;
	cin.tie(0);
	blue = 0; white = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	find(0, 0, n);
	cout << white << '\n' << blue << '\n';
}
*/

// 백준 1021번 회전하는 큐 
/*
#include<deque>
int main() {
	int count = 0;
	int n, m;
	cin >> n >> m;
	deque<int> dq;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		int index;
		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == num) {
				index = i;
				break;
			}
			
		}
		if (index < dq.size() - index) {
			while (true) {
				if (dq.front() == num) {
					dq.pop_front();
					break;

				}
				count++;
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			while (true) {
				if (dq.front() == num) {
					dq.pop_front();
					break;
				}
				count++;
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}
	cout << count;
}
*/

// 백준 1966번 프린터 큐
/*
#include<queue>

int main() {
	int t;
	cin.tie(0);
	cin >> t;
	int nowidx, prior;
	for (int test = 0; test < t; test++) {
		int n, m;
		int cnt = 0;
		queue < pair<int, int>> que;
		priority_queue<int> pq;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			que.push({ i,k });
			pq.push(k);
		}
		while (que.size()) {
			nowidx = que.front().first;
			prior = que.front().second;
			que.pop();

			if (pq.top() == prior) {
				++cnt;
				pq.pop();
				if (nowidx == m)
					break;
			}
			else {
				que.push({ nowidx, prior });
			}
		}
		cout << cnt << '\n';
	}
}
*/
// 백준 11866번 요세푸스 문제 0
/*
#include <queue>
int main() {
	queue<int> que;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		que.push(i);
	}
	cout << "<";
	while (!que.empty()) {
		for (int i = 0; i < k - 1; i++) {
			que.push(que.front());
			que.pop();
		}
		cout << que.front();
		que.pop();
		if (!que.empty()) {
			cout << ", ";
		}
	}
	cout << ">" << '\n';
	
}*/

// 백준 2164번 카드2
/*
#include<queue>
int main() {
	queue<int> que;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		que.push(i);
	while (que.size() != 1) {
		que.pop();
		int k = que.front();
		que.pop();
		que.push(k);
	}
	cout << que.front() << '\n';
}
*/

// 백준 18258번 큐2
/*

#include<queue>
#include <cstring>
char str[10];
int main() {
	cin.tie(0);

	cin.sync_with_stdio(false);
	queue<int> que;

	int n;
	cin >> n;
	int x;

	for (int i = 0; i < n; i++) {
		cin >> str;
		
		if (!strcmp(str, "push")) {
			cin >> x;
			que.push(x);
		}
		else if (!strcmp(str, "size")) {
			cout << que.size() << '\n';
		}
		else if (!strcmp(str,"empty")) {
			cout << que.empty() << '\n';
		}
		else {
			if (que.size() == 0)
				cout << -1 << '\n';
			else if (!strcmp(str, "pop")) {
				cout << que.front() << '\n';
				que.pop();
			}
			else if (!strcmp(str, "front")) {
				cout << que.front() << '\n';
			}
			else if (!strcmp(str, "back")) {
				cout << que.back() << '\n';
			}
		}			
	}

}*/

// 백준 13414번 수강신청
/*
#include<vector>
#include<string>
int main() {
	int k, l;
	cin.tie(0);
	cin >> k >> l;
	vector<string> arr;
	//vector 중간삭제느림,검색속도 좋음
	vector<string> real;
	for (int i = 0; i < l; i++) {
		string str;
		cin >> str;
		arr.push_back(str);
	}
	for (int i = l - 1; i >= 0; i--) {
		string str = arr[i];
		if (find(real.begin(), real.end(), str) == real.end()) {
			real.push_back(str);
		}
	}
	int size = real.size();
	for (int i = size - 1; i >= size - k && i >= 0; i--) {
		cout << real[i] << '\n';
	}
}*/


// 백준 2004번 조합 0의 개수 
/*
long long two, five;
int n_to_twofive(long long n,bool plus) {
	int _two = 0, _five = 0;
	for (long long i = 2; i <= n; i *= 2) {
		_two += n / i;
	}
	for (long long i = 5; i <= n; i *= 5) {
		_five += n / i;
	}
	plus ? (two += _two, five += _five) : (two -= _two, five -= _five);
	return 0;
}
int main() {
	cin.tie(0);
	two = five = 0;
	long long n, m;
	cin >> n >> m;
	n_to_twofive(n, true);
	n_to_twofive(m, false);
	n_to_twofive(n - m, false);
	cout << min(five, two);
	
}*/


// 백준 1676번 팩토리얼 0의 개수 
/*
int main() {
	int n;
	cin >> n;
	int five = 0;
	for (int i = 5; i <= n; i*=5) {
		five += n / i;
	}
	cout << five << '\n';
}
*/

// 백준 9375번 패션왕 신해빈 
/*
#include<string>
#include<map>
int main() {
	cin.tie(0);
	map<string, int> style;
	
	int testcase;
	cin >> testcase;
	for (int t = 0; t < testcase; t++) {
		int n;
		cin >> n;
		style.clear();
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str >> str;
			
			if (style.find(str) == style.end()) {
				style.insert(make_pair(str, 1));
			}
			else
				style[str]++;
		}
		int k = 1;
		for (map<string,int>::iterator it = style.begin(); it != style.end(); it++) {
			k *= (it->second + 1);
		}
		cout << k - 1 << '\n';
	}

}
*/
// 백준 11051번 이항계수2 -dp 
/*
int dp[1001][1001] = { 0, };
int main() {
	int n, k;
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		dp[i][1] = i;
		dp[i][i] = dp[i][0] = 1;
	}
	for (int i = 3; i <= n; i++) {
		for (int j = 2; j < i; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;

		}
	}
	cout << dp[n][k] << '\n';
}
*/

// 백준 11050번 이항계수1 
/*
int find_Bc(const int& a,const int& b) {
	int aa = 1, bb = 1;
	for (int i = 0; i < b; i++) {
		aa *= (a - i);
		bb *= (b - i);
	}
	return aa / bb;
}
int main() {
	int a, b;
	cin.tie(0);
	cin >> a >> b;
	cout << find_Bc(a, b);
}*/


// 백준 3036번 링 
/*
int gcd(int p, int q) {
	return q ? gcd(q, p % q) : p;
}
int main() {
	int n;
	cin.tie(0);
	cin >> n;
	int arr[100] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < n; i++) {
		int g;
		if (arr[0] > arr[i]) {
			g = gcd(arr[0], arr[i]);
		}
		else
			g = gcd(arr[i], arr[0]);
		cout << arr[0] / g << '/' << arr[i] / g << '\n';
	}
}*/

// 백준 2981번 검문
/*
#include <vector>
int arr[100];
int gcd(int p, int q) {
	if (q == 0) return p;
	return gcd(q, p % q);
}
int main() {
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int g;
	g = arr[1] - arr[0];
	for (int i = 1; i < n - 1; i++) {
		g = gcd(g, arr[i + 1] - arr[i]);
	}
	vector<int> ans;
	for (int i = 2; i * i <= g; i++)
		if (!(g % i)) {
			ans.push_back(i);
			if (i != g / i) ans.push_back(g / i);
		}
	ans.push_back(g);
	sort(ans.begin(), ans.end());
	for (int& a : ans)
		cout << a << " ";
	return 0;
}
*/

// 백준 2609번 최대 공약수와 최소공배수
/*
int main() {
	int a, b;
	cin >> a >> b;
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	for (int i = a; i >= 1; i--) {
		if (a % i == 0 && b % i == 0) {
			cout << i << '\n';
			break;
		}
	}
	for (int i = b;; i++) {
		if (i % a == 0 && i % b == 0) {
			cout << i << '\n';
			break;
		}
	}
}*/


// 백준 11653번 소인수 분해
/*
int main() {
	cin.tie(0);
	int n;
	cin >> n;
	while (n != 1) {
		for (int i = 2;; i++) {
			if (n % i == 0) {
				cout << i << '\n';
				n /= i;
				break;
			}
		}
	}
}
*/
// 백준 1037번 약수 
/*
int arr[51] = {};
int main() {
	int n;
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cout << arr[0] * arr[n - 1] << '\n';
}
*/

// 백준 5086번 배수와 약수 
/*
int main() {
	cin.tie(0);
	int a, b;
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0) {
			break;
		}
		if (a % b==0) {
			cout << "multiple\n";
		}
		else if (b % a == 0) {
			cout << "factor\n";

		}
		else {
			cout << "neither\n";

		}
	}
}
*/


// 백준 1541번 잃어버린 괄호 
/*
#include<string>
int main() {
	string str, temp = "";
	cin.tie(0);
	cin >> str;
	
	int result = 0;
	bool minus = false;
	for (int i = 0; i <= str.size(); i++) {
		if (str[i] != '+' && str[i] != '-' && str[i] != NULL) {
			temp += str[i];

		}
		else {
			if (minus) {
				result -= stoi(temp);
			}
			else
				result += stoi(temp);
			temp = "";
			if (str[i] == '-')
				minus = true;
		}
	}
	cout << result << '\n';
}
*/

// 백준 11399번 ATM 
/*
int arr[1001] = { 0, };
int main() {
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int _min = 0;
	for (int i = 0; i < n; i++) {
		_min += (n - i) * arr[i];
	}
	cout << _min << '\n';
}
*/


// 백준 11047번 동전0 
/*
int arr[11] = { 0, };
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int min = 0;
	for (int i = n; i >= 1; i--) {
		min += k / arr[i];
		k %= arr[i];
	}
	
	cout << min << '\n';
}
*/

// 백준 12865번 평범한 배낭 
/*
int DP[101][100001] = { 0, };
int main() {
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	for (int n = 1; n <= N; n++) {
		int w, v;
		cin >> w >> v;
		for (int k = 1; k <= K; k++) {
			if (w <= k) {
				DP[n][k] = max(DP[n - 1][k], DP[n - 1][k - w] + v);
			}
			else {
				DP[n][k] = DP[n - 1][k];
			}
		}
	}
	cout << DP[N][K] << '\n';

}
*/
// 백준 1912번 연속합 
/*
int DP[1000001] = { 0, };
int main() {
	cin.tie(0);
	int N;
	cin >> N;
	//이 부분 0으로 하면 max가 음수일때는 제대로 안나옴
	int _max = -1001;
	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		if (DP[i - 1] > 0) {
			DP[i] = DP[i - 1] + k;
		}
		else {
			DP[i] = k;
		}
		_max = max(_max, DP[i]);
	}
	
	cout << _max << '\n';
}
*/

// 백준 9251번 LCS
/*
int DP[1001][1001] = { 0, };

int main() {
	cin.tie(0);
	string str1, str2;
	int len1, len2;
	cin >> str1 >> str2;
	len1 = str1.length();
	len2 = str2.length();
	for (int i = 1; i <= len1; i++) {
		
		for (int j = 1; j <= len2; j++) {
			if (str1[i - 1] != str2[j - 1]) {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
			else {
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
		}
	}
	cout << DP[len1][len2] << '\n';
} 
*/