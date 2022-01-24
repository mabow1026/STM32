#include <stdio.h>
#include <math.h>
#include "vector.h"

void cmulVec(double *outp, double *inp, double k, int num){
    int i;
	for(i = 0; i < num; i++)
		outp[i] = k * inp[i];
}
