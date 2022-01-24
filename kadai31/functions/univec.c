#include <stdio.h>
#include <math.h>
#include "vector.h"

void uniVec(double *inp, double *outp, int num){
    cmulVec(outp,inp,1.0/calcLen(inp,num),num);
}
