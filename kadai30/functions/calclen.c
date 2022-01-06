#include <stdio.h>
#include <math.h>

double calcLen(double *dp, int num){
    double sum=0.0;
    int i;

    for(i = 0; i < num; i++)
        sum += dp[i] * dp[i];

    return sqrt(sum);
}
