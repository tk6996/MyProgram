#include<stdio.h>
#include<windows.h>
void draw_ship()
{
    printf("<-0-> ");
}
void gotoxy(int x,int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    gotoxy(x,y);
    draw_ship();
    return 0;
}