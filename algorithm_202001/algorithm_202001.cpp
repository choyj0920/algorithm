
#include "pch.h"
//여기부터 복사 제출
#include <iostream>
#include <algorithm>
#include <vector>
//#include <cstdio>
//#include <string>
using namespace std;


//백준 14889번 스타트와 링크
#define MAX 20
int N;
int sum;
int div_N;
int _min = 1000000;
int member[(MAX / 2) + 1];
int arr[MAX + 1][MAX + 1];

void find(const int& cnt, const int& first) { //지금 멤버수와 다음멤버
	//완성 되었으면
	if (cnt == div_N) {
		int hap = 0;
		int other_hap = 0;
		vector<int> v;
		for (int i = 1; i <= div_N; i++) {
			v.push_back(member[i]);
		}
		for (int i = 1; i < N; i++) {
			for (int j = i + 1; j <= N; j++) {
				vector<int>::iterator iter1, iter2;
				iter1 = find(v.begin(), v.end(), i);
				iter2 = find(v.begin(), v.end(), j);
				if (iter1 != v.end() && iter2 != v.end())
					hap += (arr[i][j] + arr[j][i]);
				else if (iter1 == v.end() && iter2 == v.end())
					other_hap += (arr[i][j] + arr[j][i]);
			}

		}
		hap = hap - other_hap;
		if (hap < 0)
			hap = -hap;
		if (_min > hap) {
			_min = hap;
		}
		return;
	}

	//완성이 안되면 멤버 더하기
	for (int i = first; i <= N; i++) {
		member[cnt + 1] = i;
		find(cnt + 1, i + 1);
	}
	//테스트3
}
int main() {
	cin.tie(0);
	cin >> N;
	div_N = N / 2;
	sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;
			sum += tmp;
			arr[i][j] = tmp;
		}
	}
	member[1] = 1;
	find(1, 1 + 1);

	cout << _min << '\n';


}

//백준 14888번 연산자 끼워 넣기 
/*
int _max = -1000000000;
int _min = 1000000000;
int N;

int oper[4];
int* arr;

void find(const int& plus, const int& minus, const int& multi,
	const int& divid, const int& num, const int& cnt) {
	if (cnt == N - 1) {
		if (_max < num)
			_max = num;
		if (_min > num)
			_min = num;
		return;
	}
	int nextcnt = cnt + 1;
	if (plus > 0)
		find(plus - 1, minus, multi, divid, num + arr[nextcnt], nextcnt);
	if (minus > 0)
		find(plus, minus - 1, multi, divid, num - arr[nextcnt], nextcnt);
	if (multi > 0)
		find(plus, minus, multi - 1, divid, num * arr[nextcnt], nextcnt);
	if (divid > 0)
		find(plus, minus, multi, divid - 1, num / arr[nextcnt], nextcnt);

}

int main() {
	cin.tie(0);
	cin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}
	find(oper[0], oper[1], oper[2], oper[3], arr[0], 0);

	delete arr;

	cout << _max << '\n' << _min;
}
*/

//백준 1931번 회의실배정
/*
int N;
vector<pair<int, int>>v;
int find() {
	int time = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		if (time <= v[i].second) {
			time = v[i].first;
			cnt++;
		}
	}
	return cnt;
}
int main() {
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back(make_pair(end, start));
	}
	sort(v.begin(), v.end());
	cout << find() << '\n';

}*/


//백준 2580번 스도쿠 
/*

vector<pair<int, int>>voidcell;

int sudoku[9][9];


bool check_hori(const int& r, const int& num){
	for (int c = 0; c < 9; c++) {
		if (sudoku[r][c] == num) {
			return false;
		}
	}
	return true;
}
bool check_verti(const int& c, const int& num){
	for (int r = 0; r < 9; r++) {
		if (sudoku[r][c] == num) {
			return false;
		}
	}
	return true;
}
bool check_squ(int r, int c, int num) {
	r = r / 3;
	c = c / 3;
	for (int rr = r * 3; rr < (r * 3) + 3; rr++) {
		for (int cc = c * 3; cc < (c * 3) + 3; cc++) {
			if (sudoku[rr][cc] == num)
				return false;
		}
	}
	return true;
}

bool check_cell(const int& r, const int& c, const int& num) {
	return check_hori(r, num) && check_verti(c, num) && check_squ(r, c, num);
}
void insert() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int tmp;
			cin >> tmp;
			sudoku[i][j] = tmp;
			if (tmp == 0)
				voidcell.push_back(make_pair(i, j));
		}
	}
}

void find(int n) {
	if (n == voidcell.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << " ";
			}
			cout << '\n';
		}
		exit(0);
	}
	for (int i = 1; i <= 9; i++) {
		int r = voidcell[n].first;
		int c = voidcell[n].second;
		if (check_cell(r, c, i)) {
			sudoku[r][c] = i;
			find(n + 1);
			sudoku[r][c] = 0;

		}
	}
}
int main() {
	insert();
	find(0);
}
*/

//백준 9663 n-queen 
/*
int N;
#define MAX 15
int cnt;
int layout[MAX];


void find(const int& n) {
	bool wrong;

	if (n == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		wrong = false;
		for (int j = 0; j < n; j++) {
			if (layout[j] == i || abs(n - j) == abs(i - layout[j])) {
				wrong = true;
				break;
			}
		}
		if (!wrong) {
			layout[n] = i;
			find(n + 1);
		}
	}

}
int main() {
	cin.tie(0);
	cnt = 0;
	cin >> N;
	find(0);

	cout << cnt << "\n";
}
*/


//백준	15652번 N과 M(4) 
/*

#define MAX 8+1

int list[MAX] = { 0, };
int N, M;


void Dfs(const int& n,const int& k) {
	if (n == M) {
		for (int i = 0; i < M; i++) {
			cout << list[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = k; i <= N; i++) {
		list[n] = i;
		Dfs(n + 1, i);
	}
}

int main() {
	cin.tie(0);
	cin >> N >> M;

	Dfs(0,1);

}*/


//백준	15651번 N과 M(3) 
/*

#define MAX 8+1

int list[MAX] = { 0, };
int N, M;


void Dfs(const int& n) {
	if (n == M) {
		for (int i = 0; i < M; i++) {
			cout << list[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		list[n] = i;
		Dfs(n + 1);
	}
}

int main() {
	cin.tie(0);
	cin >> N >> M;

	Dfs(0);

}*/

//백준	15650번 N과 M(2) 
/*
#define MAX 8+1

int checked[MAX] = { 0, };
int list[MAX] = { 0, };
int N, M;


void Dfs(const int& n,const int& k) {
	if (n == M) {
		for (int i = 0; i < M; i++) {
			cout << list[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = k; i <= N; i++) {
		if (!checked[i]) {
			checked[i] = true;
			list[n] = i;
			Dfs(n + 1,i+1);
			checked[i] = false;
		}
	}
}

int main() {
	cin.tie(0);
	cin >> N >> M;

	Dfs(0,1);

}
*/

//백준	15649번 N과 M(1) 
/*
#define MAX 8+1

int checked[MAX] = { 0, };
int list[MAX] = { 0, };
int N, M;


void Dfs(const int& n) {
	if (n == M) {
		for (int i = 0; i < M; i++) {
			cout << list[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!checked[i]) {
			checked[i] = true;
			list[n] = i;
			Dfs(n + 1);
			checked[i] = false;
		}
	}
}

int main() {
	cin.tie(0);
	cin >> N >> M;

	Dfs(0);

}
*/

//백준 10814번
/*
bool lesscheck(const pair<int, string>& a, const pair<int, string>& b) {
	if (a.first < b.first)
		return true;
	else
		return false;
}
int main() {
	cin.tie(0);
	int N;
	cin >> N;

	vector < pair<int, string>> v;
	v.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	stable_sort(v.begin(), v.end(), lesscheck);
	for (int i = 0; i < N; i++)
		cout << v[i].first << " " << v[i].second << "\n";

}*/

//백준 1181번 단어정렬
/*
bool strLess(const string& a, const string& b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	return a.size() < b.size();
}
int main() {
	vector<string> strs;
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		char c[51];
		scanf("%s", c);
		string str(c);
		strs.push_back(str);
	}

	vector<string>::iterator iter;
	vector<string>::iterator end_iter;

	sort(strs.begin(), strs.end(), strLess);

	end_iter = unique(strs.begin(), strs.end());

	for (iter = strs.begin(); iter != end_iter; iter++) {
		printf("%s\n", (*iter).c_str());

	}

}*/


//백준 11650,11651 좌표정렬하기
/*
#include <vector>
int main(void) {
	int N;
	cin >> N;
	vector<vector<int>> arr(N, vector<int>(2, 0));
	for (int i = 0; i < N; i++) {
		cin >> arr[i][0];
		cin >> arr[i][1];
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i][0] << " " << arr[i][1] << '\n';
	}

}*/

/*
struct MyStruct
{
	int x, y;
	void print() {
		cout << x << " " << y << endl;
		return;
	}
};
bool CheckLess(const MyStruct a, const MyStruct b) {
	if (a.x != a.x) {
		return a.x < b.x;
	}
	else {
		return a.y < b.y;
	}
}
int main() {
	int N;
	cin >> N;
	MyStruct* Pos = new MyStruct[N];
	for (int i = 0; i < N; i++) {
		cin >> Pos[i].x >> Pos[i].y;
	}
	sort(Pos, Pos + N, CheckLess);

	for (int i = 0; i < N; i++) {
		Pos[i].print();
	}
}*/

//백준 1427 소트인사이드
/*
bool dd(const char a, const char b) {
	return a > b;
}
int main() {
	char ss[10] = { 0, };
	cin >> ss;
	sort(ss, ss + 10, dd);

	cout << ss;
}*/

//백준 2108 통계학
/*
#include<cmath>

const int MAX = 500000;
int arr[MAX] = { 0, };
int check[8001] = { 0, }; //

int main() {
	cin.tie(NULL);
	int N;
	cin >> N;

	float sum = 0;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		sum += k;
		arr[i] = k;
		check[k+4000]++;
	}
	float aver = sum / (double)N;

	sort(arr, arr + N);

	//최빈 값.
	int beenNum=-1, bincount = 0;
	bool second = false;
	for (int i = 0; i < 8001; i++) {
		if (check[i] > bincount) {
			beenNum = i;
			bincount = check[i];
			second = false;
		}
		else if (check[i] == bincount && (!second)) {
			beenNum = i;
			second = true;
		}

	}

	//출력부
	cout << round(aver) << "\n" << arr[N / 2] << "\n" << beenNum - 4000 << "\n" << arr[N - 1] - arr[0];

}
*/

//백준 2750,2751 수 정렬하기
/*
#include <queue>

int main() {
	int cnt;
	priority_queue<int> que;
	cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		int n;
		cin >> n;
		que.push(-n);
	}

	while (!que.empty()) {
		cout << -que.top() << "\n";
		que.pop();
	}
}
*/


//백준 1436 영화감독 숌
/*
int main() {
	int n;
	cin >> n;
	int i, flag, cnt = 0;
	int tmp;
	i = 0;
	while (++i) {
		tmp = i, flag = 0;
		while (tmp) {
			if (tmp % 1000 == 666)
				flag = 1;
			tmp /= 10;
		}
		if (flag) {
			cnt++;
			if (cnt == n) break;
		}

	}
	cout << i << "\n";
}
*/

//백준 1018 체스판 다시 칠하기
/*
int main() {
	int N, M;
	cin >> N >> M;

	int min = 64;
	int total = 64;
	char** pan = new char*[N];
	for (int i = 0; i < N; i++) {
		pan[i] = new char[M];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> pan[i][j];
		}
	}

	for (int i = 0; i < N-7; i++) {
		for (int j = 0; j < M-7; j++) {
			int k = 0;
			for (int y = i; y < i+8; y++) {
				for (int x = j; x < j+8; x++) {
					if ((x + y) % 2) {
						if (pan[y][x] == 'W') {
							k++;
						}
					}
					else {
						if (pan[y][x] == 'B') {
							k++;
						}
					}
				}
			}
			if (k > total - k)
				k = total - k;
			if (min > k)
				min = k;
		}
	}
	cout << min << "\n";
}
*/

//백준 7568 덩치 
/*
struct Dungchi
{
	int ki;
	int mooga;
};

int main() {
	int N;
	cin >> N;
	Dungchi* dungchi = new Dungchi[N];
	for (int i = 0; i < N; i++) {
		cin >> dungchi[i].ki >> dungchi[i].mooga;
	}

	for (int i = 0; i < N; i++) {
		int rank = 1;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (dungchi[i].ki < dungchi[j].ki && dungchi[i].mooga < dungchi[j].mooga) {
				rank++;
			}
		}
		cout << rank << "\n";
	}
} */

// 백준 분해합
/*
#include <cstring>
int main() {

	long n;
	std::cin >> n;
	// 숫자자릿수부터 계산
	long m = n;
	int digit = 0;
	while (m)
	{
		m /= 10;
		digit++;
	}
	// 분해합은 최소 n - 9*n의 자릿수 부터 시작
	long begin = n - digit * 9;
	char s[10];
	long sum = 0;
	bool find = false;
	for (long i = begin; i <= n; ++i)
	{
		sprintf(s, "%ld", i);
		sum = i;
		for (int j = 0; j < strlen(s); ++j)
			sum += s[j] - '0';
		if (sum == n)
		{
			find = true;
			cout << i << "\n";
			break;
		}
	}
	if (find == false)	cout << "0\n";

	return 0;
}*/

//2798 블랙잭 
/*
int main() {
	int N, M;
	int max = 0;
	cin >> N >> M;
	int* cards = new int[N];

	for (int i = 0; i < N; i++)
		cin >> cards[i];

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				int cardnum = cards[i] + cards[j] + cards[k];
				if (cardnum > max&&cardnum <= M)
					max = cardnum;
			}
		}
	}
	cout << max;

} */

//백준 2447 별찍기-10 
/*
void draw(int x, int y) {
	while (y != 0) {
		if (x % 3 == 1 && y % 3 == 1) {
			cout << " ";
			return;
		}
		x /= 3;
		y /= 3;
	}
	cout << "*";
	return;
}

int main()
{
	int n;
	cin >> n;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			draw(x, y);
		}
		cout << "\n";
	}

}*/


