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
		if (r < mid) //���ؾ� �Ұ����� �߰����� ����
			solution(a, mid - 1, l, r, d / 2);
		else if (mid < l) //���ؾ� �Ұ����� �߰����� ������
			solution(mid + 1, b, l, r, d / 2);
		else {// ���ؾ� �� ������ �߰��� ����
			ans += d % 2;//�߰�
			//l ����  �߰� ������
			solution(a, mid - 1, l, mid - 1, d / 2);
			//�߰� �ĺ��� r����
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