#include <stdio.h>

int main() {
	double A, B;

	scanf("%lf %lf", &A, &B);
	printf("%.9e", A / B);
}