#include <stdio.h>
#include <math.h>
#include "./vector.h"
#define SIZE 3

int main(){
    double a[SIZE]={}, b[SIZE]={}, c[SIZE]={}; //a,b は入力用, cは計算結果用

    printf("Input value for Vector A \n");
    inputVec(a,SIZE);   //ベクトルAの値を配列aに代入
    printf("Input value for Vector B \n");
    inputVec(b,SIZE);   //ベクトルBの値を配列bに代入

    addVec(c, a, b, SIZE); //ベクトルA, Bの和を計算(OA+OB)

    printVec(a,SIZE);   //ベクトルAの値表示
    printf("+\n");
    printVec(b,SIZE);   //ベクトルBの値表示
    printf("=\n");
    printVec(c,SIZE);   //ベクトルA+Bの値表示
    return 0;

    return 0;
 }
