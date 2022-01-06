#include <stdio.h>

double sumVec(double *dp, int num){
    int i;
    double sum=0.0;
	for(i = 0; i < num; i++)
		sum += dp[i];

    return sum;
}
