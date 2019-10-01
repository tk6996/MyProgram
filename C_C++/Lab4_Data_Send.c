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
void send_character(int ch)
{
	char status;
	do
	{
		status = inportb(LSR) & 0x40;
	} while (status != 0x40);
	outportb(TXDATA, (char)ch);
}
int get_character(void)
{
	int status;
	do
	{
		status = inportb(LSR) & 0x01;
	} while (status != 0x01);
	return ((int)inportb(TXDATA));
}
int *createFrame(FILE *file,char *buf,int size)
{
	int chr,i;
	for (i = 0 ; i < size ; i++)
	{
		chr = fgetc(file);
		if (chr == EOF)
			break;
		*(buf+i) = (char)chr; 
	}
	*(buf+i) = '\0';
	return i != 0;
}
void main(void)
{
    char *filename = "",buf[16],ack = 0, Sn = '0';
	int i;
    FILE *f;
    clrscr();
    setup_serial();
	printf("Send file : ");
	puts(filename);
    fopen(filename,"r");
	while(createFrame(f,buf,15))
	{
		printf("Send frame : %d\n",Sn);
		printf("Data       : %s\n",buf);
		//printf("Timeout    : ");
		while(buf[i])
		{
			send_character(buf[i]);
			i++;
		}
	}
}