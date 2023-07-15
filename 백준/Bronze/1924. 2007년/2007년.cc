#include <stdio.h>

int main(void) {
	int month, days;
	scanf("%d %d", &month, &days); //31일 3일밀림 30일 2일밀림 28일 그대로
	
	for (int i = 1; i < month; i++) {
		if (i == 1 ||i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			days = days + 3;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			days = days + 2;
	}
	switch (days%7)
	{
	case 0:
		printf("SUN\n");
		break;
	case 1:
		printf("MON\n");
		break;
	case 2:
		printf("TUE\n");
		break;
	case 3:
		printf("WED\n");
		break;
	case 4:
		printf("THU\n");
		break;
	case 5:
		printf("FRI\n");
		break;
	case 6:
		printf("SAT\n");
		break;
	default:
		break;
	}
	return 0;
}