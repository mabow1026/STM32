#include <stdio.h>

void inputVec(double *dp, int num){
	int i;
	for(i = 0; i < num; i++){
		fprintf(stderr,"Input data[%d] : ", i);
		scanf("%lf", &dp[i]);  //or scanf("%d", (dp+i));
	}
}
