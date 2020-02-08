
//������� ���� ����
#include <iostream>
#include<algorithm>
using namespace std;

// ���� 11866�� �似Ǫ�� ���� 0
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
	
}

// ���� 2164�� ī��2
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

// ���� 18258�� ť2
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

// ���� 13414�� ������û
/*
#include<vector>
#include<string>
int main() {
	int k, l;
	cin.tie(0);
	cin >> k >> l;
	vector<string> arr;
	//vector �߰���������,�˻��ӵ� ����
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


// ���� 2004�� ���� 0�� ���� 
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


// ���� 1676�� ���丮�� 0�� ���� 
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

// ���� 9375�� �мǿ� ���غ� 
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
// ���� 11051�� ���װ��2 -dp 
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

// ���� 11050�� ���װ��1 
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


// ���� 3036�� �� 
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

// ���� 2981�� �˹�
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

// ���� 2609�� �ִ� ������� �ּҰ����
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


// ���� 11653�� ���μ� ����
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
// ���� 1037�� ��� 
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

// ���� 5086�� ����� ��� 
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


// ���� 1541�� �Ҿ���� ��ȣ 
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

// ���� 11399�� ATM 
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


// ���� 11047�� ����0 
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

// ���� 12865�� ����� �賶 
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
// ���� 1912�� ������ 
/*
int DP[1000001] = { 0, };
int main() {
	cin.tie(0);
	int N;
	cin >> N;
	//�� �κ� 0���� �ϸ� max�� �����϶��� ����� �ȳ���
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

// ���� 9251�� LCS
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