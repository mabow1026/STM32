#include <stdio.h>

#include "vector.h"

void calc_squareVec(double *inp, double *outp, int num) {
    mulVec(outp, inp, inp, num);
}
