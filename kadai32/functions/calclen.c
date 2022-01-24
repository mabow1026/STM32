#include <stdio.h>
#include <math.h>
#include "vector.h"

double calcLen(double *dp, int num){
    return sqrt(innerVec(dp, dp, num));
}
