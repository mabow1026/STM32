#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

double innerVec(double *inp1, double *inp2, int num) {
    double *outp;
    mulVec(outp, inp1, inp2, num);
    return sumVec(outp, num);
}
