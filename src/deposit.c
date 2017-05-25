#include "deposit.h"
float sum_analiz(int days, float sum) {
	if(days <= 30) {
		if (sum <= 100000) sum -= sum / 10;
			else sum -= sum / 10;
	}
		else if (days > 30 && days <= 120) {
			if (sum <= 100000) sum += sum * 0.02;
				else sum += sum * 0.03;
		}
			else if (days > 120 && days <= 240) {
				if (sum <= 100000) sum += sum * 0.06;
					else sum += sum * 0.08;
			}
				else if (days > 240 && days <= 365) {
						if (sum <= 100000) sum += sum * 0.12;
							else sum += sum * 0.15;
				}
	return sum;
}

int correct_analiz(int days, float sum) {
	float t;
	if(days > 0 && days < 366 && sum >= 10000) {
		t = 1;
	}
	else t = 0;
	return t;
}
