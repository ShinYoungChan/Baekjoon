#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, q;
	scanf("%d", &n);
	vector<int> music(n, 0), sum(n, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &music[i]);
	}

	for (int i = 1; i < n; i++) {
		if (music[i - 1] > music[i]) {
			sum[i] = sum[i - 1] + 1;
		}
		else {
			sum[i] = sum[i - 1];
		}
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (x == y) {
			printf("0\n");
		}
		else {
			printf("%d\n", sum[y - 1] - sum[x - 1]);
		}
	}
	return 0;
}