
//여기부터 복사 제출
#include <iostream>
#include<algorithm>
using namespace std;

// 백준 1912번 연속합
int DP[1000001] = { 0, };
int main() {
	cin.tie(0);
	int N;
	cin >> N;
	//이 부분 0으로 하면 max가 음수일때는 제대로 안나옴
	int _max = -1001;
	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		if (DP[i - 1] > 0) {
			DP[i] = DP[i - 1] + k;
		}
		else {
			DP[i] = k;
		}
		_max = max(_max, DP[i]);
	}
	
	cout << _max << '\n';
}


// 백준 9251번 LCS
/*
int DP[1001][1001] = { 0, };

int main() {
	cin.tie(0);
	string str1, str2;
	int len1, len2;
	cin >> str1 >> str2;
	len1 = str1.length();
	len2 = str2.length();
	for (int i = 1; i <= len1; i++) {
		
		for (int j = 1; j <= len2; j++) {
			if (str1[i - 1] != str2[j - 1]) {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
			else {
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
		}
	}
	cout << DP[len1][len2] << '\n';
} 
*/