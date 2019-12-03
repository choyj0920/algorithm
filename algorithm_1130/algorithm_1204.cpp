#include <iostream>

using namespace std;
//2581 소수
int main() {
	int M, N;
	cin >> M >> N;


}

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

