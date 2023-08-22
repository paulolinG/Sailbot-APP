#include "stdio.h"
#include "cutest/CuTest.h"
#include "standard_calc.h"

/**************** Tests for bound_to_180() *******************/
void test_bound_basic1(CuTest *tc) {
    float input = 180.0;
    float actual = bound_to_180(input);
    float expected = -180.0;
    CuAssertDblEquals(tc, expected, actual, 0.0001);
}
/**************** Tests for is_angle_between() *******************/
void test_between_basic1(CuTest *tc) {
    float firstAngle = 20.0;
    float secondAngle = 30.0;
    float thirdAngle = 40.0;
    CuAssertTrue(tc, is_angle_between(firstAngle, secondAngle, thirdAngle));
}

int main(int argc, char const *argv[]) {
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, test_bound_basic1);
    SUITE_ADD_TEST(suite, test_between_basic1);

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);

    return suite->failCount > 0 ? 1 : 0;
}
