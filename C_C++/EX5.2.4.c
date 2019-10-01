#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
void draw_ship(int x,int y)
{
    //system("cls");
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    printf("<-0->");
}
int main()
{
    char ch=' ';
    int x=38,y=20;
    draw_ship(x,y);
    do 
    {
        if (_kbhit())
        {
            ch=_getch();
            if(ch=='a'&&x>0) {draw_ship(--x,y);}
            if(ch=='d'&&x+5<80) {draw_ship(++x,y);}
            fflush(stdin);
        }
    Sleep(100);
    } while (ch!='x');
    return 0;
}