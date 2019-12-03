#include <iostream>

using namespace std;






//10250 ACM호텔
/*
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int H, W, N;
		cin >> H >> W >> N;
		N--;
		int Y = N % H + 1;
		int X = N / H + 1;
		cout << Y;
		if (1 <= X && X <= 9)
			cout << "0" << X << "\n";
		else
			cout <<  X << "\n";
	}

	return 0;
}
*/



//2869 달팽이는 올라가고 싶다.
/*
int main() {
	int A, B, C;
	int dis = 0;
	int i;
	cin >> A >> B >> C;
	cout<<((C-B-1) / (A - B) + 1);
}
*/