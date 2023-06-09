#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int number[6];
	int minNum[3];
	for (int i = 0; i < 6; i++)
		cin >> number[i];
	unsigned long long int n3 = pow(n, 3);
	unsigned long long int side = pow(n, 2) * 5;
	unsigned long long int maxSide = 5 * pow(n, 2) - 8 * n + 4;
	unsigned long long int secondeSide = 8 + (n - 2) * 8;
	int four = 4;

	if (n == 1) {
		sort(number, number + 6);
		printf("%d\n", number[0] + number[1] + number[2] + number[3] + number[4]);
		return 0;
	}
	minNum[0] = number[0] < number[5] ? number[0] : number[5];
	minNum[1] = number[1] < number[4] ? number[1] : number[4];
	minNum[2] = number[2] < number[3] ? number[2] : number[3];
	sort(minNum, minNum + 3);
	unsigned long long int sum = minNum[0] * maxSide + minNum[1] * secondeSide + minNum[2] * four;
	printf("%lld\n", sum);
	return 0;
}