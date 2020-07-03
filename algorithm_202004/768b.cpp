#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll n, l, r, s = 1, ans = 0;
	
void solution(ll a, ll b, ll l, ll r, ll d) {
	if (a > b || l > r) 
		return;
	else {
		ll mid = (a + b) / 2;
		if (r < mid) //구해야 할값들이 중간보다 왼쪽
			solution(a, mid - 1, l, r, d / 2);
		else if (mid < l) //구해야 할값들이 중간보다 오른쪽
			solution(mid + 1, b, l, r, d / 2);
		else {// 구해야 할 값들이 중간을 포함
			ans += d % 2;//중간
			//l 부터  중간 전까지
			solution(a, mid - 1, l, mid - 1, d / 2);
			//중간 후부터 r까지
			solution(mid + 1, b, mid + 1, r, d / 2);
		}
	}
}

int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	cin >> n >> l >> r;
	long long p = n;
	
	while (p >= 2) {
		p /= 2;
		s = s * 2 + 1;
	}
	solution(1, s, l, r, n);
	cout << ans << '\n';

}