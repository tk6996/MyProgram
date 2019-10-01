#include<stdio.h>
#include<windows.h>
void Draw_Ship()
{
    printf(" <-0-> ");
}
void gotoxy(int x,int y)
{
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
int main()
{
    int i;
    for(i=0;i<=73;i++)
    {
        gotoxy(i,20);
        Draw_Ship();
        Sleep(500);
    }
    return 0;
}