#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	vector<int> v(3, 0);

	v[0] += t / 300;
	t %= 300;
	v[1] += t / 60;
	t %= 60;
	v[2] += t / 10;
	t %= 10;
	if (t > 0)
		printf("-1\n");
	else
		printf("%d %d %d\n", v[0], v[1], v[2]);
	return 0;
}