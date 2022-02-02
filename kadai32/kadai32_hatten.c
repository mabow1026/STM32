#include <stdio.h>

#include "./functions/vector.h"
#define SIZE 4

int main(void) {
    double x[SIZE] = {1.0, 2.0, 3.0, 4.0}, y1[SIZE] = {10.0, 20.0, 30.0, 40.0}, y2[SIZE] = {7.0, 12.0, 17.0, 22.0};
    double a1, b1, a2, b2;
    leastSquare(x, y1, &a1, &b1, SIZE);
    leastSquare(x, y2, &a2, &b2, SIZE);
    printf("a1=%lf\tb1=%lf\n", a1, b1);
    printf("a1=%lf\tb1=%lf\n", a2, b2);
    return 0;
}