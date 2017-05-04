#include <stdio.h>
#include "deposit.h"

int main() {
	int s, t;
	float d;
	ml: printf("Write the days and deposit ");
	scanf("%d %f", &d, &s);
	if(d > 0 && d < 366 && s >= 10000) {
		t = analiz(d, s);
		printf("Finish summ is %d", t);
	}
	else goto ml;
	return 0;
}
