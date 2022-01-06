#include <math.h>
#include <stdio.h>

#include "./functions/vector.h"
#define SIZE 3

int main() {
    double a[SIZE] = {}, b[SIZE] = {}, ab[SIZE] = {}, uab[SIZE] = {}, len;  // a,b は入力用, ab,uabは計算結果用

    printf("Input value for Vector A \n");
    inputVec(a, SIZE);
    printf("Input value for Vector B \n");
    inputVec(b, SIZE);
    subVec(ab, b, a, SIZE);
    uniVec(ab, uab, SIZE);
    len = calcLen(ab, SIZE);
    printf("Vector AB \n");
    printVecRow(ab, SIZE);
    printf("Unit Vector AB \n");
    printVecRow(uab, SIZE);
    printf("Magnitude Vector AB\n");
    printf("%lf\n", len);
    return 0;
}
