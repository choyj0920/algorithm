#include <iostream>
#include <string>
using namespace std;


//1316 그룹단어
/*
bool checkword(string& ss) {
	int aa[26] = { 0, };
	for (int i = 0; i < ss.length(); ) {
		char c = ss[i];
		if (aa[c - 'a'] == 0) {
			aa[c - 'a'] = 1;
			while (ss[i] == c) {
				i++;
			}
		}
		else
			return false;
	}
	return true;
}
int main() {
	int count;
	int result = 0;
	cin >> count;
	for (int i = 0; i < count; i++) {
		string ss;
		cin >> ss;
		if (checkword(ss)) {
			result++;
		}
	}
	cout << result;
}
*/

//2941 크로아티아
/*
int main() {
	string ss;
	cin >> ss;
	int len = ss.length();
	int count = 0;
	for (int i = 0; i < ss.length(); i++) {
		if (ss[i] == 'c') {
			if (ss[i + 1] == '-' || ss[i + 1] == '=') {
				i++;
			}
		}
		else if (ss[i] == 'd') {
			if (ss[i + 1] == '-') {
				i++;
			}
			else if (i < ss.length() - 2) {
				if (ss[i + 1] == 'z' && ss[i + 2] == '=') {
					i++;
					i++;
				}
			}
			
		}
		else if (ss[i] == 'l' || ss[i] == 'n') {
			if (ss[i + 1] == 'j') {
				i++;
			}
		}
		else if (ss[i] == 's' || ss[i] == 'z')
			if (ss[i + 1] == '=') {
				i++;
			}
		count++;
	}
	cout << count;
}
*/

//5622 다이얼
/*
int main() {
	int total = 0;
	string ss;
	cin >> ss;
	for (int i = 0; i < ss.length(); i++) {
		int t;
		t = (ss[i] - 'A') / 3;
		switch (ss[i])
		{
		case 'S':
		case 'V':
		case 'Y':
		case 'Z':
			t--;
		default:
			break;
		}
		
		total += 3 + t;
	}
	cout << total;
}*/


//2908 상수
/*
int main() {
	int n1, n2;
	int _n1 = 0, _n2 = 0;
	cin >> n1 >> n2;

	_n1 = (n1 / 10) % 10 * 10;
	_n1 += n1 / 100; _n1 += (n1 % 10) * 100;

	_n2 = (n2 / 10) % 10 * 10;
	_n2 += n2 / 100; _n2 += (n2 % 10) * 100;
	
	cout << (_n1 < _n2 ? _n2 : _n1);

} */


//1157 단어 공부
/*
int main() {
	int aa[26]={0,};
	string ss;
	cin >> ss;
	for (int i = 0; i < ss.length(); i++) {
		if (ss[i] < 'a')
			aa[ss[i] - 'A'] += 1;
		else
			aa[ss[i] - 'a'] += 1;
	}
	int maxindex = 0, maxcount = 0;
	for (int i = 0; i < 26; i++) {
		if (maxcount < aa[i]) {
			maxindex = i;
			maxcount = aa[i];
		}
		else if (maxcount == aa[i]) {
			maxindex = 100;
		}
	}
	if (maxindex == 100)
		cout << "?";
	else
		cout <<char(maxindex + 'A');

}
*/


//2675 문자열반복
/*
int main() {
	string ss;
	int count, casecount;
	cin >> casecount;
	for (int aa = 0; aa < casecount; aa++) {
		cin >> count >> ss;
		for (int i = 0; i < ss.length(); i++) {
			for (int j = 0; j < count; j++)
				cout << ss[i];
		}
		cout << endl;
	}

} */

//10809 알파벳 찾기
/*
int main() {
	string ss;
	cin >> ss;

	int aa[26];
	for (int i = 0; i < 26; i++) {
		aa[i] = -1;
	}
	
	for (int i = 0; i < ss.length();i++) {
		int ch = ss[i] - 'a';
		if (aa[ch] == -1) {
			aa[ch] = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << aa[i] << " ";
	}
	
}
*/


//1065 한수
/*
bool hansoo(int n);
int main()
{
	int N;
	cin >> N;
	int count = 0;
	if (N == 1000)
		N = 999;
	for (int i = 1; i <= N; i++) {
		count += hansoo(i);
	}
	cout << count;
}

bool hansoo(int n) {
	int soo[3] = { 0, };
	soo[0] = n % 10;
	soo[1] = n / 10 % 10;
	soo[2] = n / 100;
	if (soo[2] != 0 ) 
		if (soo[2] - soo[1] != soo[1] - soo[0]) {
			return false;
		}
	return true;
	
}
*/