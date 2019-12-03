#include <iostream>

using namespace std;


//1193 분수 찾기
/*
int main() {
	int count = 0;
	int cou;
	int child, super;
	cin >> cou;
	for (int i = 1; true; i++) { 
		count += i;
		if (cou <= count) {
			count -= i;
			count++;
			int k = cou - count ;
			if (i % 2 == 1) {
				child = i - k;
				super = k + 1;
			}
			else {
				child = k + 1;
				super = i - k;
			}
			break;
		}
	}
	cout << child << "/" << super;
}
*/

//2292 벌집
/*
int main() {

	int count = 1;
	int room;
	cin >> room;
	int i;
	if (room == 1) {
		cout << 1;
		return 0;
	}
	for ( i = 0; true; i++) {
		count += 6 * i;
		if (count >= room)
			break;
	}
	cout << i + 1;
}
*/


//1712 손익 분기점
/*
int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	int x = C - B;
	if (x > 0) {
		cout << A / x + 1;
	}
	else
		cout << -1;
}
*/