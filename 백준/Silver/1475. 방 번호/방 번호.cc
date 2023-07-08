#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
	int num[10] = { 0 };
	int n;
	cin >> n;
	do {
		num[n % 10]++;
		n = n / 10;
	} while (n != 0);
	num[6] = num[6] + num[9];
	if (num[6] % 2 == 0)
		num[6] /= 2;
	else
		num[6] = num[6] / 2 + 1;
	int count = 1;
	for (int i = 0; i < 9; i++)
		if (num[i] > count)
			count = num[i];

	printf("%d\n", count);
	return 0;
}