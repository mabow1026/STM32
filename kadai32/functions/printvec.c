#include <stdio.h>

void printVec(double *dp, int num){
	int i;
	for(i = 0; i < num; i++)
		printf("data[%d]=%lf\n", i, dp[i]);
}
