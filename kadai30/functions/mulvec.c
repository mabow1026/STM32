#include <math.h>
#include <stdio.h>

void mulVec(double *outp, double *inp1, double *inp2, int num) {
    int i;
    for (i = 0; i < num; i++)
        outp[i] = inp1[i] * inp2[i];
}
