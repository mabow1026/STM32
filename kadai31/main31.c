#include <math.h>
#include <stdio.h>

#include "./functions/vector.h"
#define SIZE 3
#define Q4PE 9.0  //電荷量を1.0e-9とした場合の「q/4πε」

int main() {
    double a[SIZE] = {-1.0, 0.0, 0.0}, b[SIZE] = {1.0, 0.0, 0.0}, abx[SIZE], uabx[SIZE], len;  // a,b は電荷の位置, uxpは単位ベクトル用
    double x[SIZE], temp[SIZE], ans[SIZE] = {0.0, 0.0, 0.0};                                   // ansは0で初期化必要

    printf("Input Point (x,y,z) \n");
    inputVec(x, SIZE);
    //電界を計算する位置(x,y,z)を配列pに代入
    subVec(abx, x, a, SIZE);
    // APベクトルを計算(OA-OPを配列abxに代入)
    len = calcLen(abx, SIZE);
    // XPの距離を計算(変数lenに代入)
    uniVec(abx, uabx, SIZE);
    // XPの単位ベクトルを計算(単位ベクトルを配列uabxに代入)
    cmulVec(temp, uabx, Q4PE / (len * len), SIZE);
    //電界ベクトルの計算(XPの単位ベクトル(uabx)をクーロン力倍(Q4PE/距離^2)し配列tempに代入)
    addVec(ans, ans, temp, SIZE);
    // ansに電界ベクトルを加算(加算結果を配列ansに代入)
    subVec(abx, x, b, SIZE);
    // BPベクトルを計算(OB-OPを配列abxに代入)
    len = calcLen(abx, SIZE);
    // XPの距離を計算(変数lenに代入)
    uniVec(abx, uabx, SIZE);
    // XPの単位ベクトルを計算(単位ベクトルを配列uabxに代入)
    cmulVec(temp, uabx, Q4PE / (len * len), SIZE);
    //電界ベクトルの計算(XPの単位ベクトル(temp)をクーロン力倍(Q4PE/距離^2)し配列tempに代入)
    addVec(ans, ans, temp, SIZE);
    // ansに電界ベクトルを加算(加算結果を配列ansに代入)
    printf("Electric Field Vector: \t");
    printVecRow(ans, SIZE);
    return 0;
}
