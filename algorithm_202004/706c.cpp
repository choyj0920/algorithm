#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
#include <string>

using namespace std;
typedef long long ll;

const ll oo = 1e16;
const int WITHOUT_REVERSING = 0, REVERSING = 1;
bool lessstr(string aa, string bb) {
	return aa < bb;
}
string ss[100001];
ll reverse_c[100001];
ll dp[100001][2];

string rev(string s)
{
	reverse(s.begin(),s.end());

	return s;
}

int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> reverse_c[i];
	}for (int i = 1; i <= n; i++) {
		cin >> ss[i];
	}
	
	for (int i = 1; i <= n; i++) {
		dp[i][WITHOUT_REVERSING] = dp[i][REVERSING] = oo;


		if (ss[i] >= ss[i - 1])
			dp[i][WITHOUT_REVERSING] = dp[i - 1][WITHOUT_REVERSING];

		if (ss[i] >= rev(ss[i - 1]))
			dp[i][WITHOUT_REVERSING] = min(dp[i][WITHOUT_REVERSING], dp[i - 1][REVERSING]);

		if (rev(ss[i]) >= ss[i - 1])
			dp[i][REVERSING] = reverse_c[i] + dp[i - 1][WITHOUT_REVERSING];

		if (rev(ss[i]) >= rev(ss[i - 1]))
			dp[i][REVERSING] = min(dp[i][REVERSING], reverse_c[i] + dp[i - 1][REVERSING]);

		

	}

	ll ans = min(dp[n][REVERSING], dp[n][WITHOUT_REVERSING]);

	cout << (ans >= oo ? -1 : ans) << '\n';

}