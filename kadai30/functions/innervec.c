#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

double innerVec(double *inp1, double *inp2, int num) {
    double *out, sum = 0.0;
    out = (double *)malloc(num * sizeof(double));
    mulVec(out, inp1, inp2, num);
    sum = sumVec(out, num);
    free(out);
    return sum;
}
