#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
	int round, jimin, hansu;
	cin >> round >> jimin >> hansu;
	int count = 1;
	while (true)
	{
		if ((jimin % 2 != 0 && hansu % 2 == 0) && ((jimin + 1) == hansu)) {
			printf("%d\n", count);
			break;
		}
		else if ((hansu % 2 != 0 && jimin % 2 == 0) && ((hansu + 1) == jimin)) {
			printf("%d\n", count);
			break;
		}
		if (jimin % 2 == 0)
			jimin /= 2;
		else
			jimin = jimin / 2 + 1;
		if (hansu % 2 == 0)
			hansu /= 2;
		else
			hansu = hansu / 2 + 1;

		count++;
	}
	return 0;
}