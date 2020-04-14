#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
ll a[5000];

ll solution(int from, int to, ll height) {
	
	if (from >= to) return 0;
	int m = from; //min height index(from~(to-1))
	for (int i = m + 1; i < to; i++) {
		if (a[m] > a[i])
			m = i;
	}
	return min(ll(to - from), a[m] - height + solution(from, m, a[m]) + solution(m + 1, to, a[m]));

}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << solution(0, n + 1, 0);
}