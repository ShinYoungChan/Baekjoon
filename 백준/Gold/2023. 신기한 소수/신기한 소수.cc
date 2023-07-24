#pragma warning(disable:4996)

#include <cstdio>
#include <queue>

using namespace std;

bool isPrime(int num) {
	for (int i = 2; i * i <= num; i++) {
		if ((num % i) == 0)
			return false;
	}
	return true;
}
int main() {
	queue<int> nums;
	int N, size;
	// 2, 3, 5, 7
	scanf("%d", &N);
	nums.push(2);
	nums.push(3);
	nums.push(5);
	nums.push(7);

	for (int n = 1; n < N; n++) {
		size = nums.size();
		for (int i = 0; i < size; i++) {
			int num = nums.front();
			nums.pop();

			num *= 10;
			for (int j = 1; j < 10; j++) {
				if (isPrime(num + j))
					nums.push(num + j);
			}
		}
	}

	size = nums.size();
	for (int i = 0; i < size; i++) {
		printf("%d\n", nums.front());
		nums.pop();
	}
	
	return 0;
}