#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int a[5010] = { 0, };
int p[5010] = { 0 };
int main() {
	cin.tie(0); cin.sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	p[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i] = a[i] + p[i - 1];
	}

	double answer = 0;
	
	for (int i = k; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			double value = (p[j] - p[j - i]) / double(i);
			answer = max(answer, value);
		}
	}


	cout << setprecision(15)<<answer << '\n';
	
	

	
}