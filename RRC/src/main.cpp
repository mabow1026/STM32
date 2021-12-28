#include <math.h>
#include <mbed.h>

#include "function.h"
#define QUEUE_SIZE 1024

UnbufferedSerial IR(PA_2, PA_3, 8192);   // UART2
UnbufferedSerial GR(PA_9, PA_10, 8192);  // UART1
UnbufferedSerial LS(PA_0, PA_1, 8192);   // UART4

DigitalOut myled(PA_5);
Ticker warikomi;

PwmOut pwmA_1(PA_6);
PwmOut pwmA_2(PA_7);
PwmOut pwmB_1(PA_8);
PwmOut pwmB_2(PB_4);
PwmOut pwmC_1(PB_5);
PwmOut pwmC_2(PB_3);

int IR_head;
int IR_num;
int GR_head;
int GR_num;
int LS_head;
int LS_num;

int IR_count;
data_t IR_tmp[8];
int LS_count;
data_t LS_tmp[8];
int GR_count;
data_t GR_tmp[8];

float IR_deg, IR_dist;
float LS_F, LS_B, LS_R, LS_L;
float GR_deg;

data_t IR_data[QUEUE_SIZE];
data_t GR_data[QUEUE_SIZE];
data_t LS_data[QUEUE_SIZE];

// float error[2];
// float integral;
// float p, i, d;
// #define KP 0
// #define KI 0
// #define KD 0
// #define DELTA 1.0e-2

void main() {
    IR.baud(115200);
    IR.format(8, SerialBase::None, 1);
    IR.attach(IR_rx, SerialBase::RxIrq);
    GR.baud(115200);
    GR.format(8, SerialBase::None, 1);
    GR.attach(GR_rx, SerialBase::RxIrq);
    LS.baud(115200);
    LS.format(8, SerialBase::None, 1);
    LS.attach(LS_rx, SerialBase::RxIrq);
    warikomi.attach(&movement, 10ms);

    while (1) {
        if (IR.readable) {
            IR_read();
        }
        if (GR.readable) {
            GR_read();
        }
        if (LS.readable) {
            LS_read();
        }
    }
}

void IR_rx() {
    data_t val;
    IR.read(&val, 1);
    IR_enq(val);
}

void IR_read() {
    data_t val;
    IR_deq(&val);

    else if (val == 0x53) {
        IR_count = 0;
    }
    else {
        IR_count++;
    }
    IR_tmp[IR_count] = val;
    if (IR_count == 7) {
        IR_deg = 100.0f * IR_tmp[1] + 10.0f * IR_tmp[2] + IR_tmp[3];
        IR_dist = 100.0f * IR_tmp[4] + 10.0f * IR_tmp[5] + IR_tmp[6];
    }
}

void GR_rx() {
    data_t val;
    GR.read(&val, 1);
    GR_enq(val);
}

void GR_read() {
    data_t val;
    GR_deq(&val);
    if (val == 0x53) {
        GR_count = 0;
    } else {
        GR_count++;
    }
    GR_tmp[GR_count] = val;
    if (GR_count == 7) {
        GR_deg = (int)GR_tmp[2];
    }
}

void LS_rx() {
    data_t val;
    LS.read(&val, 1);
    LS_enq(val);
}

void LS_read() {
    data_t val;
    LS_deq(&val) else if (val == 0x53) { LS_count = 0; }
    else {
        LS_count++;
    }
    LS_tmp[LS_count] = val;
    if (LS_count == 7) {
        LS_F = LS_tmp[2];
        LS_B = LS_tmp[3];
        LS_R = LS_tmp[4];
        LS_L = LS_tmp[5];
    }
}

void IR_enq(data_t enq_data) {
    IR_data[(IR_head + IR_num) % QUEUE_SIZE] = enq_data;
    IR_num++;
}

void IR_deq(data_t *deq_data) {
    *deq_data = IR_data[IR_head];
    IR_head = (IR_head + 1) % QUEUE_SIZE;
    IR_num--;
    return 1;
}

void GR_enq(data_t enq_data) {
    GR_data[(GR_head + GR_num) % QUEUE_SIZE] = enq_data;
    GR_num++;
}

void GR_deq(data_t *deq_data) {
    *deq_data = GR_data[GR_head];
    GR_head = (GR_head + 1) % QUEUE_SIZE;
    GR_num--;
}

void LS_enq(data_t enq_data) {
    LS_data[(LS_head + LS_num) % QUEUE_SIZE] = enq_data;
    LS_num++;
}

void LS_deq(data_t *deq_data) {
    *deq_data = LS_data[LS_head];
    LS_head = (LS_head + 1) % QUEUE_SIZE;
    LS_num--;
}

void movement() {
    float wheelA, wheelB, wheelC, degv, swheelA, swheelB, swheelC;
    degv = (((GR_deg - 60.0f) / 60.0f) * 0.2f);
    wheelA = (IR_dist * sin(IR_deg - 60.0f)) * 0.8f;
    wheelB = (IR_dist * sin(IR_deg - 300.0f)) * 0.8f;
    wheelC = (IR_dist * sin(IR_deg - 180.0f)) * 0.8f;

    swheelA = wheelA + degv;
    swheelB = wheelB + degv;
    swheelC = wheelC + degv;

    if (swheelA > 0)  //後ろオムニホイール
    {
        pwmA_1 = fabsf(swheelA);
        pwmA_2 = 0;
    } else if (swheelA < 0) {
        pwmA_1 = 0;
        pwmA_2 = fabsf(swheelA);
    }

    if (swheelB > 0)  //右前オムニホイール
    {
        pwmB_1 = fabsf(swheelB);
        pwmB_2 = 0;
    } else if (swheelB < 0) {
        pwmB_1 = 0;
        pwmB_2 = fabsf(swheelB);
    }

    if (swheelC > 0)  //左前オムニホイール
    {
        pwmC_1 = fabsf(swheelC);
        pwmC_2 = 0;
    } else if (swheelC < 0) {
        pwmC_1 = 0;
        pwmC_2 = fabsf(swheelC);
    }
}

// float pid_culc(float feedback, float target)
// {
//   float p, i, d;

//   error[0] = error[1];
//   error[1] = feedback - target;
//   integral += (error[1] + error[0]) / 2.0 * DELTA;

//   p = KP * error[1];
//   i = KD * integral;
//   d = KD * (error[1] - error[0] / DELTA);

//   return (p + i + d);
// }