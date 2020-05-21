#include <iostream>
#include <cstdio>
#include<vector>
#include <Algorithm>
#include<string>

using namespace std;
typedef  long long  ll;

struct  node
{
	ll l, r, mini, incre;
}T[1000004];

ll A[200005];
ll N, M;
ll L, R, V;

ll build(ll k, ll L, ll R) {
	T[k].l = L; T[k].r = R; T[k].incre = 0;
	if (L == R) {
		T[k].mini = A[L]; return 0;
	}
	ll mid = (L + R) / 2;
	build((ll)k * 2, (ll)L, (ll)mid);
	build((ll)k * 2+1, (ll)mid+1, (ll)R);
	T[k].mini = min(T[k * 2].incre + T[k * 2].mini, T[k * 2 + 1].incre + T[k * 2 + 1].mini);
	return 0;
}

ll query(ll k,ll L, ll R) {
	ll mid,lret,rret;
	if (T[k].l >= L && T[k].r <= R) {
		return T[k].mini + T[k].incre;
	}
	if (T[k].l > R || T[k].r < L) {
		return 50000000000000;
	}
	mid = (T[k].l + T[k].r) / 2;
	lret = query(k*2,L,R);
	rret = query(k * 2 + 1, L, R);
	return min(lret, rret) + T[k].incre;
}

void increment(ll k, ll L, ll R, ll V) {
	if (T[k].l >= L && T[k].r <= R) {
		T[k].incre += V;
		return;
	}
	if (T[k].l > R || T[k].r < L) {
		return;
	}
	ll mid = (T[k].l + T[k].r) / 2;
	increment(k * 2, L, R, V);
	increment(k * 2 + 1, L, R, V);
	T[k].mini = min(T[k * 2].mini + T[k * 2].incre, T[k * 2 + 1].mini + T[k * 2 + 1].incre);
	return;
}


int main() {
	ll i;
	int c;
	cin >> N;
	for (i = 1; i <= N; i++) cin >> A[i];
	build((ll)1, (ll)1, (ll)N);
	cin >> M;
	for (i = 1; i <= M; i++) {
		cin >> L >> R; L++; R++;
		c = getchar();
		if (c == '\n') {
			if (L <= R) {
				cout << query((ll)1, (ll)L , (ll)R) << '\n';
			}
			else {
				cout << min(query((ll)1, 1, R), query((ll)1, L, N)) << '\n';

			}
		}
		else {
			cin >> V;
			if (L <= R) {
				increment((ll)1, L , R , V);
			}
			else {
				increment((ll)1, 1, R, V);
				increment((ll)1, L, N, V);
			}
		}
	}

}

