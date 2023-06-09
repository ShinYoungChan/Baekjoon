#include <iostream>

using namespace std;

int main()
{
	int n, m, n1;
	int money = 2100000000;
	scanf("%d %d", &n, &m);
	n1 = n;
	int set, piece;
	set = piece = 1001;
	for (int i = 0; i < m * 2; i++) {
		int asd;
		scanf("%d", &asd);
		if (i % 2 == 0 && set > asd)
			set = asd;
		else if (i % 2 != 0 && piece > asd)
			piece = asd;
	}
    if (money > piece * n)
        money = piece * n;
    for (int i = 0, j = 1; i < n; i += 6, j++) {
        int asd;
        n1 -= 6 * j;
        asd = set * j;
        if (n1 > 0)
            asd += piece * n1;
        if (money > asd)
            money = asd;
        n1 = n;
    }
	printf("%d\n", money);
	return 0;
}