#include <stdio.h>

#include "vector.h"

void uniVec(double *inp, double *outp, int num) {
    cmulVec(outp, inp, calcLen(inp, num), num);
}