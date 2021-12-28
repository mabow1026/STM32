#ifndef function_H
#define function_H

typedef char data_t;

void IR_enq(data_t enq_data);
void IR_deq(data_t *deq_data);
void GR_enq(data_t enq_data);
void GR_deq(data_t *deq_data);
void LS_enq(data_t enq_data);
void LS_deq(data_t *deq_data);
void IR_rx();
void GR_rx();
void LS_rx();
void IR_read();
void IR_proc(data_t temp_array[]);
void GR_read();
void GR_proc(data_t temp_array[]);
void LS_read();
void LS_proc(data_t temp_array[]);
void movement();
// float pid_culc(float feedback, float target);

#endif