#include "deposit.h"
#include "ctest.h"

CTEST (simpleSuit, simpleTest) {
	int real = correct_analiz (100, 200000);
	const int exp = 1;
	assert_equal (exp, real," ",0);
}

CTEST (checkSumSuit100000, analizTest100000) {
	int s, sum;	
	s = sum = 100000;
	sum -= sum * 0.1;
	ASSERT_DBL_NEAR_TOL(90000, sum, sum_analiz(30, s));
	sum = 100000;
	sum += sum * 0.02;
	ASSERT_DBL_NEAR_TOL(102000, sum, sum_analiz(120, s));
	sum = 100000;
	sum += sum * 0.06;
	ASSERT_DBL_NEAR_TOL(106000, sum, sum_analiz(240, s));
	sum = 100000;
	sum += sum * 0.12;
	ASSERT_DBL_NEAR_TOL(112000, sum, sum_analiz(300, s));
}
CTEST (checkSumSuit200000, analizTest200000) {
	int s, sum;
	s = sum = 200000;
	sum -= sum * 0.1;
	ASSERT_DBL_NEAR_TOL(180000, sum, sum_analiz(30, s));
	sum = 200000;
	sum += sum * 0.03;
	ASSERT_DBL_NEAR_TOL(206000, sum, sum_analiz(120, s));
	sum = 200000;
	sum += sum * 0.08;
	ASSERT_DBL_NEAR_TOL(208000, sum, sum_analiz(240, s));
	sum = 200000;
	sum += sum * 0.15;
	ASSERT_DBL_NEAR_TOL(215000, sum, sum_analiz(300, s));
}
