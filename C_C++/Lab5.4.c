#include<stdio.h>
#include<windows.h>
#include<conio.h>
int gotoxy(int x,int y)
{
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    return 0;
}
int erase_ship(int x,int y)
{
    gotoxy(x,y);
    printf("       ");
    return 0;
}
int Draw_Ship(int x,int y)
{
    gotoxy(x,y);
    printf(" <-0-> ");
    Sleep(100);
    return 0;
}
int main()
{
    int x=38,y=20;
    char cha=' ';
    Draw_Ship(x,y);
    do
    {
        if(_kbhit())
        {
        cha=_getch();
        if(cha=='a'&&x>0)    {erase_ship(x,y);Draw_Ship(--x,y);} 
        if(cha=='d'&&x+7<80) {erase_ship(x,y);Draw_Ship(++x,y);} 
        if(cha=='w'&&y>0)    {erase_ship(x,y);Draw_Ship(x,--y);} 
        if(cha=='s')         {erase_ship(x,y);Draw_Ship(x,++y);}
        fflush(stdin);
        }
    }
    while(cha!='x');
    return 0;
}