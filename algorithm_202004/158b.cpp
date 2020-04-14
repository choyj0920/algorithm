#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;
int main() {
	cin.tie(0); cin.sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(5, 0);
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v[temp]++;
	}
	int answer;
	answer = v[4];
	answer += v[3];

	v[1] -= v[3];
	if (v[1] < 0) v[1] = 0;

	answer += (v[2] / 2);
	if (v[2] % 2) {
		answer++;
		if (v[1] > 0)
			v[1]--;
		if (v[1] > 0)
			v[1]--;
	}

	answer += (v[1] / 4);
	if (v[1] % 4)
		answer++;

	cout << answer << '\n';
		
	
	
		

}