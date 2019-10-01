#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
void gotoxy(int,int);
void clrscr();
void delay(int);
void Draw_Ship(int,int);
void p(int,int);
int main()
{
int x=1,y=1;
char a=' ';
p(x,y);
do
{
if(_kbhit())
{
a=_getch();
if(a=='a'&&x>0)p(--x,y);
if(a=='d'&&x<79)p(++x,y);
if(a=='w'&&y>0)p(x,--y);
if(a=='s')p(x,++y);
fflush(stdin);
}
}
while(a!='x');
clrscr();
return 0;
}
void clrscr()
{
system("cls");
}
void delay(int ms)
{
Sleep(ms);
}
void gotoxy(int x,int y)
{
COORD pos={x,y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void Draw_Ship(int x,int y)
{
printf("0");
if(x+1!=80){gotoxy(x+1,y);printf(">");}
if(x-1!=-1){gotoxy(x-1,y);printf("<");}
gotoxy(x,y+1);printf("v");
if(y-1!=-1){gotoxy(x,y-1);printf("^");}
}
void p(int x,int y)
{
clrscr();
gotoxy(x,y);
Draw_Ship(x,y);
delay(100);
}