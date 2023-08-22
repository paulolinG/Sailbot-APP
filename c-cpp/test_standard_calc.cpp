#include "stdio.h"
#include "cutest/CuTest.h"
#include "standard_calc.h"

/**************** Tests for bound_to_180() *******************/
void test_bound_equalTo180(CuTest *tc) {
    CuAssertDblEquals(tc, -180, bound_to_180(180), 0.0001);
}

void test_bound_greaterThan180(CuTest *tc) {
    CuAssertDblEquals(tc, -159.445, bound_to_180(200.555), 0.0001);
}

void test_bound_greaterThan360(CuTest *tc) {
    CuAssertDblEquals(tc, 20.555, bound_to_180(380.555), 0.0001);
}

void test_bound_greaterThan540(CuTest *tc) {
    CuAssertDblEquals(tc, -159.445, bound_to_180(560.555), 0.0001);
}

void test_bound_inBoundaries(CuTest *tc) {
    CuAssertDblEquals(tc, 0, bound_to_180(0), 0.0001);
}

void test_bound_equalToN180(CuTest *tc) {
    CuAssertDblEquals(tc, -180, bound_to_180(-180), 0.0001);
}

void test_bound_lessThanN180(CuTest *tc) {
    CuAssertDblEquals(tc, 139.6, bound_to_180(-220.4), 0.0001);
}

void test_bound_lessThanN360(CuTest *tc) {
    CuAssertDblEquals(tc, -40.4, bound_to_180(-400.4), 0.0001);
}

void test_bound_lessThanN540(CuTest *tc) {
    CuAssertDblEquals(tc, 139.6, bound_to_180(-580.4), 0.0001);
}
/**************** Tests for is_angle_between() *******************/
void test_between_bounding(CuTest *tc) {
    CuAssertTrue(tc, is_angle_between(-580.4, 160, 180));
}

void test_between_firstGreaterSecond(CuTest *tc) {
    CuAssertTrue(tc, is_angle_between(0, 20, 30));
}

void test_between_secondGreaterFirst(CuTest *tc) {
    CuAssertTrue(tc, is_angle_between(30, 20, 0));
}

void test_between1(CuTest *tc) {
    CuAssertTrue(tc, is_angle_between(-50, 10, 60));
}

void test_between2(CuTest *tc) {
    CuAssertTrue(tc, is_angle_between(160, 170, -180));
}

int main(int argc, char const *argv[]) {
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, test_bound_equalTo180);
    SUITE_ADD_TEST(suite, test_bound_greaterThan180);
    SUITE_ADD_TEST(suite, test_bound_greaterThan360);
    SUITE_ADD_TEST(suite, test_bound_greaterThan540);
    SUITE_ADD_TEST(suite, test_bound_inBoundaries);
    SUITE_ADD_TEST(suite, test_bound_equalToN180);
    SUITE_ADD_TEST(suite, test_bound_lessThanN180);
    SUITE_ADD_TEST(suite, test_bound_lessThanN360);
    SUITE_ADD_TEST(suite, test_bound_lessThanN540);

    SUITE_ADD_TEST(suite, test_between_bounding);
    SUITE_ADD_TEST(suite, test_between_firstGreaterSecond);
    SUITE_ADD_TEST(suite, test_between_secondGreaterFirst);
    SUITE_ADD_TEST(suite, test_between1);
    SUITE_ADD_TEST(suite, test_between2);

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);

    return suite->failCount > 0 ? 1 : 0;
}
