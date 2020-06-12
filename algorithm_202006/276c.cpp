#include <iostream>
#include <cstdio>
#include<vector>
#include <Algorithm>
#include<string>

using namespace std;
typedef  long long  ll;
ll a[200005];
ll cnt[200005];
ll n_cnt[200005];
int n, q;
int l, r;
ll yy;

bool desc(const ll a, const ll b) { return a > b; }

ll read(int x)
{
	int sum = 0;
	while (x > 0)
	{
		sum += cnt[x];
		x -= (x & -x);
	}
	return sum;
}


int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	while (q--) {
		cin >> l >> r;
		while (l <= n) {
			cnt[l] += 1;
			l += (l & -l);
		}
		yy = r + 1;
		while (yy <= n) {
			cnt[yy] -= 1;
			yy += (yy & -yy);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		
		n_cnt[i] = read(i);
	}


	sort(n_cnt + 1, n_cnt + n + 1);
	sort(a + 1, a + n + 1);
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		
		ans += a[i] * n_cnt[i];
	}
	

	cout << ans << '\n';

}