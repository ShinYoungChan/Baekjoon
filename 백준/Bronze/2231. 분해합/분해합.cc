#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
	int num, num2;
	int count = 0;
	bool div = false;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int sum = i;
		int j = i;
		do {
			sum += (j % 10);

		} while ((j /= 10) != 0);
		if (num == sum) {
			printf("%d\n", i);
			div = true;
			break;
		}
	}
	if (!div)
		printf("0\n");
	return 0;
}
