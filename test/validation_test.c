#include <deposite.h>
#include <ctest.h>

CTEST (validationSuit, validationCorrectAnaliz) {
	
	ASSERT_EQUAL (0, correct_analiz(-1,200000));
	ASSERT_EQUAL (0, correct_analiz(-100,200000));
	ASSERT_EQUAL (0, correct_analiz(100,1));
	ASSERT_EQUAL (0, correct_analiz(-100,1));
	
	ASSERT_EQUAL (1, correct_analiz(0,20000));
	ASSERT_EQUAL (1, correct_analiz(100,200000));
	ASSERT_EQUAL (1, correct_analiz(365,999999));
	
	ASSERT_EQUAL (0, correct_analiz(366,100000));
	ASSERT_EQUAL (0, correct_analiz(38999,10));
}
