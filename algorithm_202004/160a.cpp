#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

int a[200];
int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	int n;
	long long ans = 0;
	int total=0, half;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		total += a[i];
	}
	half = total / 2;
	int sum = 0;
	sort(a, a + n);
	int i = n - 1;
	while (sum <= half) {
		sum += a[i]; ans++; i--;
	}

	
	cout << ans << '\n';


}