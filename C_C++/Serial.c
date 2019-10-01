#include<stdio.h>
typedef struct {
    int baud_rate;
    unsigned char nbit;
    unsigned char parity;
    unsigned char nstop_bit;
    } serial_struct;
    pserial_init(serial_struct);
void serial_init(serial_struct a);
int main()
{
    Serial.print("Hello");
}
void serial_init(serial_struct a){
    serial_struct serial;
    serial.baud_rate = 9600;
    serial.nbit = 8;
    serial.parity = 0;
    serial.nstop_bit = 1;
    serial_init(serial);
}