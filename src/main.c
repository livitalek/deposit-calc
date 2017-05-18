#include <stdio.h>
#include "deposit.h"

int main() {
	int d;
	float s, t;
	ml: printf("Write the days and deposit ");
	scanf("%d %f", &d, &s);
	t = analiz2 (d, s);
	if (t == 0) goto ml;
	else t = analiz (d, s);
	printf("Finish summ is %f", t);
	return 0;
}
