#include <iostream>

using namespace std;

int main(void) {
	long long x, y, rate;
	cin >> x >> y;
	rate = (double)y * 100 / x;
	long long start = 0;
	long long end = x;
	int result = 0;
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long nRate = (double)(y + mid) * 100 / (x + mid);
		if (nRate > rate) {
			//더 적게가능
			result = x + mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	cout << (result != 0 ? result - x : -1) << endl;
	return 0;
}