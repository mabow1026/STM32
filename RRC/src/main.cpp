#include <math.h>
#include <mbed.h>

Serial IR(PC_6, PC_7, 8192);   // USART6
Serial GR(PA_9, PA_10, 8192);  // USART1
Serial LS(PC_12, PD_2, 8192);  // USART5

DigitalOut myled(PA_5);
Ticker warikomi;

PwmOut pwmA_1(PB_4);
PwmOut pwmA_2(PB_5);
PwmOut pwmB_1(PB_6);
PwmOut pwmB_2(PB_7);
PwmOut pwmC_1(PB_8);
PwmOut pwmC_2(PB_9);

int IR_count;
u_int8_t IR_tmp[8];
int LS_count;
u_int8_t LS_tmp[8];
int GR_count;
u_int8_t GR_tmp[8];

float IR_deg, IR_dist;
float LS_F, LS_B, LS_R, LS_L;
float GR_deg;

// float error[2];
// float integral;
// float p, i, d;
// #define KP 0
// #define KI 0
// #define KD 0
// #define DELTA 1.0e-2

void IR_read();
void GR_read();
void LS_read();
void movement();
void wrap_ball();

void main() {
    IR.baud(115200);
    IR.format(8, SerialBase::None, 1);
    IR.attach(IR_read, SerialBase::RxIrq);
    GR.baud(115200);
    GR.format(8, SerialBase::None, 1);
    GR.attach(GR_rx, SerialBase::RxIrq);
    LS.baud(115200);
    LS.format(8, SerialBase::None, 1);
    LS.attach(LS_rx, SerialBase::RxIrq);
    warikomi.attach(&movement, 10ms);

    while (1) {
    }
}

void IR_read() {
    u_int8_t receive = IR.getc();
    if (receive == 0x53) {
        IR_count = 0;
    } else {
        IR_count++;
    }
    IR_tmp[IR_count] = receive;
    if (IR_count == 7) {
        IR_deg = 100.0f * IR_tmp[1] + 10.0f * IR_tmp[2] + IR_tmp[3];
        IR_dist = 100.0f * IR_tmp[4] + 10.0f * IR_tmp[5] + IR_tmp[6];
    }
}

void GR_read() {
    u_int8_t reveive = GR.getc();
    if (receive == 0x53) {
        GR_count = 0;
    } else {
        GR_count++;
    }
    GR_tmp[GR_count] = receive;
    if (GR_count == 7) {
        GR_deg = (float)GR_tmp[2];
    }
}

void LS_read() {
    u_int8_t receive = LS.getc();
    if (receive == 0x53) {
        LS_count = 0;
    } else {
        LS_count++;
    }
    LS_tmp[LS_count] = val;
    if (LS_count == 7) {
        LS_F = (float)LS_tmp[2];
        LS_B = (float)LS_tmp[3];
        LS_R = (float)LS_tmp[4];
        LS_L = (float)LS_tmp[5];
    }
}

void movement() {
    float wheelA, wheelB, wheelC, degVec, pwmA, pwmB, pwmC;
    degVec = (((GR_deg - 60.0f) / 60.0f) * 0.2f);
    wheelA = (IR_dist * sin(IR_deg - 60.0f)) * 0.8f;   //右モーター
    wheelB = (IR_dist * sin(IR_deg - 300.0f)) * 0.8f;  //後モーター
    wheelC = (IR_dist * sin(IR_deg - 180.0f)) * 0.8f;  //左モーター

    pwmA = wheelA + degVec;
    pwmB = wheelB + degVec;
    pwmC = wheelC + degVec;

    if (pwmA > 0) {
        pwmA_1 = fabsf(pwmA);
        pwmA_2 = 0;
    } else if (pwmA < 0) {
        pwmA_1 = 0;
        pwmA_2 = fabsf(pwmA);
    }

    if (pwmB > 0) {
        pwmB_1 = fabsf(pwmB);
        pwmB_2 = 0;
    } else if (pwmB < 0) {
        pwmB_1 = 0;
        pwmB_2 = fabsf(pwmB);
    }

    if (pwmC > 0) {
        pwmC_1 = fabsf(pwmC);
        pwmC_2 = 0;
    } else if (pwmC < 0) {
        pwmC_1 = 0;
        pwmC_2 = fabsf(pwmC);
    }
}

void wrap_ball() {
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