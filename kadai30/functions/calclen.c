#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

double calcLen(double *dp, int num) {
    double *out, sum = 0.0;
    out = (double *)malloc(num * sizeof(double));
    calc_squareVec(dp, out, num);
    sum = sqrt(sumVec(out, num));
    free(out);
    return sum;
}
