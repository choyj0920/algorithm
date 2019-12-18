#include <iostream>

using namespace std;
//9020 °ñµå ¹ÙÈåÀÇ ÃßÃø
#include <list>
int a[10001] = { 0,1, };
int main() {
	int max = 0;
	int n;
	int* arr;
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (max < arr[i])
			max = arr[i];
	}
	
	for (int i = 2; i <= max; i++)
		for (int j = 2; j * i <= max; j++)
			a[i * j] = 1;

	for (int i = 0; i < n; i++) {
		int num = arr[i];
		int num1 = 0, num2 = 0;
		for (int j = 2; j <= num/2; j++) {
			if (a[j] == 0 && a[num - j] == 0) {
				num1 = j;  num2 = num - j;
			}
		}
		cout << num1 << " " << num2 << endl;
	}
}