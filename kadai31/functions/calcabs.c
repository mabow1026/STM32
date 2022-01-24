#include <stdio.h>
#include <math.h>
#include "vector.h"

void calc_absVec(double *inp, double *outp, int num){
    int i;
	for(i = 0; i < num; i++)
		outp[i] = fabs(inp[i]);
}
