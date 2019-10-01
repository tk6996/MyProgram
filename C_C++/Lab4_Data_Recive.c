#define COM3BASE 0x3E8
#define COM4BASE 0x2E8
#define TXDATA COM3BASE
#define LCR (COM3BASE + 3)
#define LSR (COM3BASE + 5)
#include <stdio.h>
#include <conio.h>
#include <dos.h>
void setup_serial(void)
{
	outportb(LCR, 0x80);
	outportb(TXDATA, 0x0C);
	outportb(TXDATA + 1, 0x00);
	outportb(LCR, 0x0A);
}
void send_character(char ch)
{
	char status;
	do
	{
		status = inportb(LSR) & 0x40;
	} while (status != 0x40);
	outportb(TXDATA, ch);
}
char get_character(void)
{
	int status;
	do
	{
		status = inportb(LSR) & 0x01;
	} while (status != 0x01);
	return ((char)inportb(TXDATA));
}
void main(void)
{
    char filename[100];
    FILE *f;
    clrscr();
    setup_serial();
    fopen(filename,"r");

}