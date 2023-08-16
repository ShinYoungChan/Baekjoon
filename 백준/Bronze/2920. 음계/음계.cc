#include <iostream>

using namespace std;

int main(void)
{
	int num[8];
	bool ascending, descending, mixed;
	ascending = descending = mixed = false;
	for (int i = 0; i < 8; i++) {
		cin >> num[i];
	}

	if (num[0] == 1) {
		ascending = true;
		descending = mixed = false;
		for (int i = 1; i < 8; i++) {
			if (num[i] != num[0] + i) {
				mixed = true;
				ascending = false;
				break;
			}
		}

	}
	else if (num[0] == 8) {
		descending = true;
		ascending = mixed = false;
		for (int i = 1; i < 8; i++) {
			if (num[i] != num[0] - i) {
				mixed = true;
				descending = false;
				break;
			}
		}
	}
	else {
		ascending = descending = false;
		mixed = true;
	}
	if (ascending)
		cout << "ascending" << endl;
	if (descending)
		cout << "descending" << endl;
	if (mixed)
		cout << "mixed" << endl;
	return 0;
}