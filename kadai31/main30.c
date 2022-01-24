#include <stdio.h>
#include <math.h>
#include "./functions/vector.h"
#define SIZE 3

int main(){
    double a[SIZE], b[SIZE], ab[SIZE], uab[SIZE], len; //a,b は入力用, cは計算結果用
    
    printf("Input value for Vector A \n");
    inputVec(a,SIZE);
    printf("Input value for Vector B \n");
    inputVec(b,SIZE);

    subVec(ab, b, a, SIZE); //ABベクトルを計算(OB-OA)
    uniVec(uab, ab, SIZE); //ABベクトルの単位ベクトルを計算

    printf("Vector AB \n");
    printVecRow(ab,SIZE);
    printf("Unit Vector AB \n");
    printVecRow(uab,SIZE);
    printf("Length of Unit Vector AB = % lf\n", calcLen(uab, SIZE));
    return 0;
 }
