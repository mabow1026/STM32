#include <stdio.h>
#include <math.h>
#include "vector.h"

double innerVec(double *inp1, double *inp2, int num){
    double out[num];
    mulVec(out, inp1, inp2, num);
    return sumVec(out,num);
}
