#include <stdio.h>

#include "vector.h"

void leastSquare(double *x, double *y, double *a, double *b, int num) {
    double XkXk, XkYk, Xk, Yk;
    XkXk = innerVec(x, x, num);
    XkYk = innerVec(x, y, num);
    Xk = sumVec(x, num);
    Yk = sumVec(y, num);

    *a=(num*XkYk-(Xk*Yk))/(num*XkXk-(XkXk));
    *b=(XkXk*Yk-(XkYk*Xk))/(num*XkXk-XkXk);

}