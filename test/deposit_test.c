#include <deposit.h>
#include <ctest.h>

CTEST (simpleSuit, simpleCorrectTest) {
	int res = correct_analiz (100, 200000);
	const int exp = 0;
	ASSERT_EQAUL (exp, res);
}

CTEST (checkSumSuit, analizTest) {
	float s;
	
	s = 100000;
	ASSERT_DBL_NEAR_TOL(90000., analiz(30, s), 1);
	ASSERT_DBL_NEAR_TOL(102000., analiz(120, s), 1);
	ASSERT_DBL_NEAR_TOL(106000., analiz(240, s), 1);
	ASSERT_DBL_NEAR_TOL(112000., analiz(300, s), 1);

	s = 200000;
	ASSERT_DBL_NEAR_TOL(180000., analiz(30, s), 1);
	ASSERT_DBL_NEAR_TOL(206000., analiz(120, s), 1);
	ASSERT_DBL_NEAR_TOL(208000., analiz(240, s), 1);
	ASSERT_DBL_NEAR_TOL(215000., analiz(300, s), 1);
}
