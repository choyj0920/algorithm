
//여기부터 복사 제출
#include <iostream>
#include<algorithm>
using namespace std;

// 백준 1037번 약수
int arr[51] = {};
int main() {
	int n;
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cout << arr[0] * arr[n - 1] << '\n';
}


// 백준 5086번 배수와 약수 
/*
int main() {
	cin.tie(0);
	int a, b;
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0) {
			break;
		}
		if (a % b==0) {
			cout << "multiple\n";
		}
		else if (b % a == 0) {
			cout << "factor\n";

		}
		else {
			cout << "neither\n";

		}
	}
}
*/


// 백준 1541번 잃어버린 괄호 
/*
#include<string>
int main() {
	string str, temp = "";
	cin.tie(0);
	cin >> str;
	
	int result = 0;
	bool minus = false;
	for (int i = 0; i <= str.size(); i++) {
		if (str[i] != '+' && str[i] != '-' && str[i] != NULL) {
			temp += str[i];

		}
		else {
			if (minus) {
				result -= stoi(temp);
			}
			else
				result += stoi(temp);
			temp = "";
			if (str[i] == '-')
				minus = true;
		}
	}
	cout << result << '\n';
}
*/

// 백준 11399번 ATM 
/*
int arr[1001] = { 0, };
int main() {
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int _min = 0;
	for (int i = 0; i < n; i++) {
		_min += (n - i) * arr[i];
	}
	cout << _min << '\n';
}
*/


// 백준 11047번 동전0 
/*
int arr[11] = { 0, };
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int min = 0;
	for (int i = n; i >= 1; i--) {
		min += k / arr[i];
		k %= arr[i];
	}
	
	cout << min << '\n';
}
*/

// 백준 12865번 평범한 배낭 
/*
int DP[101][100001] = { 0, };
int main() {
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	for (int n = 1; n <= N; n++) {
		int w, v;
		cin >> w >> v;
		for (int k = 1; k <= K; k++) {
			if (w <= k) {
				DP[n][k] = max(DP[n - 1][k], DP[n - 1][k - w] + v);
			}
			else {
				DP[n][k] = DP[n - 1][k];
			}
		}
	}
	cout << DP[N][K] << '\n';

}
*/
// 백준 1912번 연속합 
/*
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
*/

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