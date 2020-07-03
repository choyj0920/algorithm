#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
int main() {
	cin.tie(0); cin.sync_with_stdio(false);

	int two, three, five, six, tfs;
	long long ans = 0;
	cin >> two >> three >> five >> six;

	if (six < five) five = six;
	tfs = five;

	if (two < five)
		tfs = two;

	ans = (long long)256 * tfs;

	two -= tfs;

	if (three < two) two = three;
	ans += (long long)32 * two;

	cout << ans << '\n';
	




}