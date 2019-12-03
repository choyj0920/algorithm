#include <iostream>

using namespace std;

//2775 부녀회장이 될테야 
/*
int people[15][15] = { 0, };
int cou_peo(int floor, int hosoo) {
	if (floor == 0)
		return hosoo;
	if (hosoo == 1)
		return 1;
	if (people[floor][hosoo] == 0) 
		people[floor][hosoo] = cou_peo(floor - 1, hosoo) + cou_peo(floor, hosoo - 1);
	
	return people[floor][hosoo];
}
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int fl, ho;
		cin >> fl >> ho;
		cout << cou_peo(fl, ho);
	}
}
*/