#include <stdio.h>
#include <math.h>
#include "vector.h"

void addVec(double *outp, double *inp1, double *inp2, int num){
    int i;
	for(i = 0; i < num; i++)
		outp[i] = inp1[i] + inp2[i];
}
