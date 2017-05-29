#include "deposit.h"
#include "ctest.h"

CTEST (validationSuit1, validationCorrectAnaliz1) {
	ASSERT_EQUAL (0, correct_analiz(-1,200000));
}
CTEST (validationSuit2, validationCorrectAnaliz2) {
	ASSERT_EQUAL (0, correct_analiz(-100,200000));
}
CTEST (validationSuit3, validationCorrectAnaliz3) {
	ASSERT_EQUAL (0, correct_analiz(100,1));
}
CTEST (validationSuit4, validationCorrectAnaliz4) {
	ASSERT_EQUAL (0, correct_analiz(-100,1));
}
CTEST (validationSuit5, validationCorrectAnaliz5) {
	ASSERT_EQUAL (1, correct_analiz(10,20000));
}
CTEST (validationSuit6, validationCorrectAnaliz6) {
	ASSERT_EQUAL (1, correct_analiz(100,200000));
}
CTEST (validationSuit7, validationCorrectAnaliz7) {
	ASSERT_EQUAL (1, correct_analiz(365,999999));
}
CTEST (validationSuit8, validationCorrectAnaliz8) {
	ASSERT_EQUAL (0, correct_analiz(366,100000));
}
CTEST (validationSuit9, validationCorrectAnaliz9) {
	ASSERT_EQUAL (0, correct_analiz(38999,10));
}
