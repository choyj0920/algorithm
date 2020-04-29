#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;



typedef struct beacon
{
	int pos;
	int power;
}BEACONS;

BEACONS beacons[100005];
int dp[100005];

int less_beacons(const void* a, const void* b) {
	return ((BEACONS *)a)->pos - ((BEACONS*)b)->pos;
}

int binarySearch(int len, int key) {
	int left, right, mid;
	left = 0, right = len-1;
	while (left < right - 1) {
		mid = (left + right) / 2;
		if (beacons[mid].pos >=key) {
			right = mid - 1;
		}
		else
			left = mid;
	}

	if (beacons[right].pos < key)
		return right;

	if (beacons[left].pos >= key)
		--left;
	return left;

}

int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> beacons[i].pos >> beacons[i].power;
	qsort(beacons, n, sizeof(BEACONS), less_beacons);

	
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		int last = binarySearch(n, beacons[i].pos-beacons[i].power);
		if (last == -1)
			dp[i] = dp[i - 1];
		else
			dp[i] = dp[last] + 1;

	}

	int max_destroy = 0;

	for (int i = 0; i < n; i++) {
		if (max_destroy <  dp[i])
			max_destroy =  dp[i];
	}
	
	cout << (n-max_destroy) << '\n';
	
}





