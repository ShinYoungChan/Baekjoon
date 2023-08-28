#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class person {
public:
	string name;
	int day, month, year;
public:
	person() { name = ""; day = month = year = 0; }
	bool operator <(person& person) {
		if (this->year == person.year) {
			if (this->month == person.month) {
				return this->day < person.day;
			}
			return this->month < person.month;
		}
		return this->year < person.year;
	}
};

int main(void)
{
	int n;
	cin >> n;
	person* p;
	p = new person[n];
	for (int i = 0; i < n; i++) {
		cin >> p[i].name >> p[i].day >> p[i].month >> p[i].year;
	}
	sort(p, p + n);
	cout << p[n - 1].name << "\n" << p[0].name << endl;
	delete[] p;
	return 0;
}