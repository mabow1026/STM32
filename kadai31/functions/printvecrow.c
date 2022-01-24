#include <stdio.h>

void printVecRow(double *dp, int num){
	int i;
	for(i = 0; i < num; i++)
		printf("%lf, ", dp[i]);

    printf("\n");
}
