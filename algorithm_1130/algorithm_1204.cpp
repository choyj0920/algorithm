#include <iostream>

using namespace std;
//4948 베르트랑 공준
#include <list>
int a[246913] = { 0,1, };
int main() {
	//에라스토테네스 체
	int max = 0;
	int n = -1;
	list<int> list;
	while (n != 0) {
		cin >> n;
		if (n > max) {
			max = n;
		}
		if (n != 0)
			list.push_back(n);
	}
	for (int i = 2; i <= max * 2; i++)
		for (int j = 2; j * i <= max * 2; j++)
			a[i * j] = 1;

	std::list<int>::iterator it;
	for (it = list.begin(); it != list.end(); it++) {
		int count = 0;
		for (int t = *it; t < (*it) * 2; ) {
			if (a[++t] == 0)
				count++;
		}
		cout << count << "\n";
	}
}


//1929 소수구하기
/*
int a[1000001] = { 0,1, };
int main() {
	//에라스토테네스 체
	int M, N; //1을 제외 모두 소수 설정
	cin >> M >> N;
	for (int i = 2; i <= N; i++)
		for (int j = 2; j * i <= N; j++)
			a[i * j] = 1;
	for (int i = M; i <= N; i++) {
		if(!a[i])
			cout << i << "\n";
	}
}*/

//2581 소수
/*
int sosoo(int N) {
	if (N == 1) return 0;
	for (int i = 2; i < N; i++) {
		if (N % i == 0) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int M, N;
	cin >> M >> N;
	int count = 0, min;

	for (int i = M; i <= N; i++) {
		if (sosoo(i)) {
			if (count == 0)
				min = i;
			count += i;
		}
	}
	if (count == 0)
		cout << -1;
	else
		cout << count << "\n" << min;

}
*/

//1978 소수 찾기 
/*
int main() {
	int casecount, count = 0;
	cin >> casecount;
	for (int c = 0; c < casecount; c++) {
		int N;
		cin >> N;
		if (N == 1) continue;
		bool issosoo = true;
		for (int i = 2; i < N; i++) {
			if (N % i == 0) {
				issosoo = false;
				break;
			}
		}
		if (issosoo)
			count++;		
	}
	cout << count;
}*/

//1011 fly me
/*
#include <math.h>
int main() {
	int count;
	cin >> count;
	
	for (int c = 0; c < count; c++) {
		int x, y;
		cin >> x >> y;
		long long i = 1;
		while (i * i <= (y - x))
			i++;
		i--;
		long long remaining = (y - x) - (i * i);
		remaining = (long long)ceil((double)remaining / (double)i);
		cout << i * 2 - 1 + remaining << "\n";
		
	}
}
*/

