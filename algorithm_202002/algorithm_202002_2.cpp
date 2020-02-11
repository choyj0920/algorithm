
///������� ���� ����
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


// ���� 11279�� �ִ���
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
	
}


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