// baek2042 구간 합 구하기
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;
long long init(vector<long long>&, vector<long long>&, int, int, int);
long long sum(vector<long long>&, int, int, int, int, int);
void update(vector<long long>&, int, int, int, int, long long);

int main() {

	int m, n, k;

	scanf("%d %d %d", &n, &m, &k);

	double h =ceil(log2(n));
	double size = pow(2,h+1); 

	vector<long long> a(n);
	vector<long long> tree(size);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}

	init(a, tree, 1, 0, n - 1);

	m += k;

	for (int i = 0; i < m; i++) {
		
		int t1;
		scanf("%d",&t1);

		if (t1 == 1) {
			int t2; long long t3;
			scanf("%d %lld", &t2, &t3);

			t2 -= 1;
			long long diff = t3 - a[t2];
			a[t2] = t3;
			update(tree, 1, 0, n - 1, t2, diff);
		}
		else {
			int t2, t3;
			scanf("%d %d", &t2, &t3);
			printf("%lld\n", sum(tree, 1, 0, n - 1, t2 - 1, t3 - 1));
		}

	}

	return 0;
}


long long init(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = a[start];
	}
	else {
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

long long sum(vector<long long>& tree, int node, int start, int end, int left, int right) {

	if (right < start || end < left) {
		return 0;
	}
	
	if (left <= start && end <= right) {
		return tree[node];
	}

	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff) {

	if (index < start || end < index) {
		return;
	}

	tree[node] += diff;

	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
		
}