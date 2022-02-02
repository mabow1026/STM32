#include <stdio.h>

#include "./functions/vector.h"
#define SIZE 4

int main(void) {
    double x[SIZE] = {1.0, 2.0, 3.0, 4.0}, y1[SIZE] = {10.0, 20.0, 30.0, 40.0}, y2[SIZE] = {7.0, 12.0, 17.0, 22.0};
    double a1, b1, a2, b2;
    double XkXk, XkYk, Xk, Yk;
    XkXk = innerVec(x, x, SIZE);
    XkYk = innerVec(x, y1, SIZE);
    Xk = sumVec(x, SIZE);
    Yk = sumVec(y1, SIZE);
    a1 = (SIZE * XkYk - (Xk * Yk)) / (SIZE * XkXk - (XkXk));
    b1 = (XkXk * Yk - (XkYk * Xk)) / (SIZE * XkXk - XkXk);
    XkXk = innerVec(x, x, SIZE);
    XkYk = innerVec(x, y2, SIZE);
    Xk = sumVec(x, SIZE);
    Yk = sumVec(y2, SIZE);
    a2 = (SIZE * XkYk - (Xk * Yk)) / (SIZE * XkXk - (XkXk));
    b2 = (XkXk * Yk - (XkYk * Xk)) / (SIZE * XkXk - XkXk);

    printf("a1=%lf\tb1=%lf\n", a1, b1);
    printf("a1=%lf\tb1=%lf\n", a2, b2);
    return 0;
}