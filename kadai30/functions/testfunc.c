#include <stdio.h>

#include "test.h"
#include "vector.h"

void testfunc(void) {
    double dd1[3] = {1.0, 2.0, -3.0}, dd2[3] = {1.0, -2.0, 3.0}, dd3[3] = {-4.0, 1.0, 2.0};
    testStart("sumVec");  // sumVec関数のテストを記述(d1,d2,d3の配列を用いる)
    assert_equals_double(sumVec(dd1, 3), 0.0);
    assert_equals_double(sumVec(dd2, 3), 2.0);
    assert_equals_double(sumVec(dd3, 3), -1.0);
    testEnd();

    testStart("averageVec");  // averageVec関数のテストを記述(d1,d2,d3の配列を用いる)
    assert_equals_double(averageVec(dd1, 3), 0.0);
    assert_equals_double(averageVec(dd2, 3), 2.0 / 3.0);
    assert_equals_double(averageVec(dd3, 3), -1.0 / 3.0);
    testEnd();

    double out[3];
    double ansabs1[3] = {1.0, 2.0, 3.0}, ansabs2[3] = {1.0, 2.0, 3.0}, ansabs3[3] = {4.0, 1.0, 2.0};
    testStart("calc_absVec");  // calc_absVec関数のテストを記述(d1,d2,d3の配列を用いる)
    calc_absVec(dd1, out, 3);
    assert_equals_vec(out, ansabs1, 3);
    calc_absVec(dd2, out, 3);
    assert_equals_vec(out, ansabs2, 3);
    calc_absVec(dd3, out, 3);
    assert_equals_vec(out, ansabs3, 3);
    testEnd();

    double anssquare1[3] = {1.0, 4.0, 9.0}, anssquare2[3] = {1.0, 4.0, 9.0}, anssquare3[3] = {16.0, 1.0, 4.0};
    testStart("calc_squareVec");  // calc_squareVec関数のテストを記述(d1,d2,d3の配列を用いる)
    calc_squareVec(dd1, out, 3);
    assert_equals_vec(out, anssquare1, 3);
    calc_squareVec(dd2, out, 3);
    assert_equals_vec(out, anssquare2, 3);
    calc_squareVec(dd3, out, 3);
    assert_equals_vec(out, anssquare3, 3);
    testEnd();

    double anscmul1[3] = {1.0, 2.0, -3.0}, anscmul2[3] = {-2.0, 4.0, -6.0}, anscmul3[3] = {2.0, -0.5, -1.0};
    testStart("cmulVec");  // cmulVec関数のテストを記述(d1,d2,d3の配列を用いる)
    cmulVec(out, dd1, 1.0, 3);
    assert_equals_vec(out, anscmul1, 3);
    cmulVec(out, dd2, -2.0, 3);
    assert_equals_vec(out, anscmul2, 3);
    cmulVec(out, dd3, -0.5, 3);
    assert_equals_vec(out, anscmul3, 3);
    testEnd();

    double ansadd1[3] = {2.0, 0.0, 0.0}, ansadd2[3] = {-3.0, -1.0, 5.0}, ansadd3[3] = {-3.0, 3.0, -1.0};
    testStart("addVec");  // addVec関数のテストを記述(d1,d2,d3の配列を用いる)
    addVec(out, dd1, dd2, 3);
    assert_equals_vec(out, ansadd1, 3);
    addVec(out, dd2, dd3, 3);
    assert_equals_vec(out, ansadd2, 3);
    addVec(out, dd3, dd1, 3);
    assert_equals_vec(out, ansadd3, 3);
    testEnd();

    double anssub1[3] = {0.0, 4.0, -6.0}, anssub2[3] = {5.0, -3.0, 1.0}, anssub3[3] = {-5.0, -1.0, 5.0};
    testStart("subVec");  // calc_absVec関数のテストを記述(d1,d2,d3の配列を用いる)
    subVec(out, dd1, dd2, 3);
    assert_equals_vec(out, anssub1, 3);
    subVec(out, dd2, dd3, 3);
    assert_equals_vec(out, anssub2, 3);
    subVec(out, dd3, dd1, 3);
    assert_equals_vec(out, anssub3, 3);
    testEnd();

    double ansmul1[3] = {1.0, -4.0, -9.0}, ansmul2[3] = {-4.0, -2.0, 6.0}, ansmul3[3] = {-4.0, 2.0, -6.0};
    testStart("mulVec");  // calc_absVec関数のテストを記述(d1,d2,d3の配列を用いる)
    mulVec(out, dd1, dd2, 3);
    assert_equals_vec(out, ansmul1, 3);
    mulVec(out, dd2, dd3, 3);
    assert_equals_vec(out, ansmul2, 3);
    mulVec(out, dd3, dd1, 3);
    assert_equals_vec(out, ansmul3, 3);
    testEnd();

    // double dd1[3]={1.0,2.0,-3.0},dd2[3]={1.0,-2.0,3.0},dd3[3]={-4.0,1.0,2.0};
    testStart("innerVec");  // innerVec関数のテストを記述(d1,d2,d3の配列を用いる)
    assert_equals_double(innerVec(dd1, dd2, 3), -12.0);
    assert_equals_double(innerVec(dd2, dd3, 3), 0.0);
    assert_equals_double(innerVec(dd3, dd1, 3), -8.0);

    testEnd();

    testStart("calcLen");  // innerVec関数のテストを記述(d1,d2,d3の配列を用いる)
    assert_equals_double(calcLen(dd1, 3), sqrt(14.0));
    assert_equals_double(calcLen(dd2, 3), sqrt(14.0));
    assert_equals_double(calcLen(dd3, 3), sqrt(21.0));
    testEnd();

    double ansuni1[3] = {3.741657, 7.483315, -11.224972}, ansuni2[3] = {3.741657, -7.483315, 11.224972}, ansuni3[3] = {-18.330303, 4.582576, 9.165151};
    testStart("uniVec");
    uniVec(dd1, out, 3);
    assert_equals_vec(out, ansuni1, 3);
    uniVec(dd2, out, 3);
    assert_equals_vec(out, ansuni2, 3);
    uniVec(dd3, out, 3);
    assert_equals_vec(out, ansuni3, 3);
    testEnd();
}
