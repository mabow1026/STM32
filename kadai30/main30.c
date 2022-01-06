#include <math.h>
#include <stdio.h>

#include "./functions/vector.h"
#define SIZE 3

int main() {
    double a[SIZE] = {}, b[SIZE] = {}, ab[SIZE] = {}, uab[SIZE] = {}, len;  // a,b は入力用, ab,uabは計算結果用

    printf("Input value for Vector A \n");
    //ベクトルAの値を配列aに代入
    printf("Input value for Vector B \n");
    //ベクトルBの値を配列bに代入

    //ベクトルABを計算(OB-OA)
    //ベクトルABの大きさを計算
    //ベクトルABの単位ベクトルを計算

    printf("Vector AB \n");
    //ベクトルABの値を表示
    printf("Unit Vector AB \n");
    //ベクトルABの単位ベクトルの値を表示
    //ベクトルABの単位ベクトルの大きさを表示
    return 0;
}
