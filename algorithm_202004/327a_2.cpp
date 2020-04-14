
#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;
int n;
int p[101];

int find_2() {
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int cnt = 0;
			cnt = p[i - 1]
				+ (j - i + 1) - (p[j] - p[i - 1])
				+ p[n] - p[j];


			if (answer < cnt)
				answer = cnt;
			
		}
	}

	
	return answer;
}

int main() {
	cin.tie(0); cin.sync_with_stdio(false);

	cin >> n;
	p[0] = 0;
	int temp;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		p[i] = p[i - 1] + temp;

	}
	cout << find_2() << '\n';


}

