#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, ans = INT32_MIN;
string str;

int calc(int a, int b, char op) {
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
}

void dfs(int idx, int sum) {
	if (idx > n - 1) {
		ans = ans > sum ? ans : sum;
		return;
	}

	char op = idx == 0 ? '+' : str[idx - 1];

	// 괄호 묶기
	if (idx + 2 < n) {
		int num = calc(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
		dfs(idx + 4, calc(sum, num, op));
	}
	// 괄호 안 묶기
	dfs(idx + 2, calc(sum, str[idx] - '0', op));
}

int main() {
	cin >> n;
	cin >> str;

	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}