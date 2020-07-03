#include <iostream>
#include<vector>
#include <Algorithm>
#include<string>
using namespace std;
int N;
vector<int> Last;
vector<int> AA;
int LL[100005];
int LL_2[100005];
int LL_3[100005];
int ans[100005];

int LIS(vector<int>& A,int begin,int end,int L[]) {
	vector<int>::iterator it;
	Last = vector<int>();
	Last.push_back(-100);
	int maxL = 0;
	for (int i = begin; i <= end; i++) {
		if (Last.back() < A[i])
			Last.push_back(A[i]);
		it = lower_bound(Last.begin(), Last.end(), A[i]);
		*it = A[i];
		L[i] = it - Last.begin();
		maxL = max(L[i], maxL);
	}
	
	return maxL;
}
bool check(const int& a, const int& b) {
	return a > b;
}

int LIS_rev(vector<int>& A, int begin, int end, int L[]) {
	vector<int>::iterator it;
	Last = vector<int>();
	Last.push_back(1000000);
	int maxL = 0;
	for (int i = end; i >= begin; i--) {
		if (Last.back() > A[i])
			Last.push_back(A[i]);
		it = lower_bound(Last.begin(), Last.end(), A[i], check);
		*it = A[i];
		L[i] = it - Last.begin();
		maxL = max(L[i], maxL);
	}

	return maxL;

}

int LIS_except(vector<int>& A, int begin, int end,int exc, int L[]) {
	vector<int>::iterator it;
	Last = vector<int>();
	Last.push_back(-100);
	int maxL = 0;
	for (int i = begin; i <= end; i++) {
		if (i == exc)
			continue;
		if (Last.back() < A[i])
			Last.push_back(A[i]);
		it = lower_bound(Last.begin(), Last.end(), A[i]);
		*it = A[i];
		L[i] = it - Last.begin();
		maxL = max(L[i], maxL);
	}

	return maxL;
}	


int main() {
	int i;
	cin >> N;
	AA = vector<int>(N+1);
	for (int i = 1; i <= N; i++) {
		cin >> AA[i];
	}
	int maxLen = LIS(AA, 1, N, LL);
	LIS_rev(AA, 1, N, LL_2);

	for (int i = 1; i <= N; i++) {
		int f1 = LL[i];
		int f2 = LL_2[i];
		if (f1 + f2 - 1 < maxLen)
			ans[i] = 1;
		else {						
			ans[i] = 3;			
		}
	}
	int maxi = 0,mini=100005;
	for (int i= 1; i <= N; i++) {
		if (ans[i] != 1) {
			if (AA[i] <= maxi) ans[i] = 2;
				maxi = max(maxi, AA[i]);
		}
	}
	for (int i = N; i >= 1; i--) {
		if (ans[i] != 1) {
			if (AA[i] >= mini) ans[i] = 2;
			mini = min(mini, AA[i]);
		}
	}
	
	for (int i = 1; i <= N; i++) {
		cout << ans[i];
	}

	cout << endl;

}