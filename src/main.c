#include <stdio.h>
#include "deposit.h"

int main() {
	int d;
	float s, t;
	ml: printf("Write the days and deposit ");
	scanf("%d %f", &d, &s);
	t = correct_analiz (d, s);
	if (t == 0) goto ml;
	else t = sum_analiz (d, s);
	printf("Finish summ is %f", t);
	return 0;
}
