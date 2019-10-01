#include<stdio.h>
#include<windows.h>
#include<conio.h>
void gotoxy(int, int );
void draw_ship(int,int);
void setcursor(boolean);
void setcolor(int,int);
int bullet(int*,int*);
int main()
{
    char ch='.';
    int x=38,y=20,d=0,b=0,bx1,by1,ce=0;
    boolean l,r,sb=0,ab=0;
    setcursor(0);
    setcolor(2,4);
    draw_ship(x,y);
    do {
        if (kbhit()){
        ch=getch();
        switch(ch)
        {
        case 'a' : d=1;break;
        case 'd' : d=2;break;
        case 's' : d=3;break;
        case ' ' : sb=1;break;
        default : ;
        }
        fflush(stdin);
        }
        if(d==1&&x>0) {draw_ship(--x,y);}
        if(d==2&&x<=74) {draw_ship(++x,y);}
        if(sb==1)
        {
            ce=1;
        }
        if(ce==1)
            {
            if(ab==0) {bx1=x+2;by1=y;gotoxy(bx1,--by1);setcolor(2,0);printf("^");ab=1;}
            else if(by1>0) bullet(&bx1,&by1); else {gotoxy(bx1,by1);printf(" ");ce=0;ab=0;} 
            }
        sb=0;
    Sleep(100);
    }while (ch!='x');
    setcolor(7,0);
    return 0;
}
void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
void draw_ship(int x,int y)
{
    gotoxy(x,y); setcolor(2,4); printf("<-0->");setcolor(0,0); if(x<=74) printf(" "); 
    if(x>0) gotoxy(--x,y);printf(" ");
}
void setcursor(boolean visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console,&lpCursor);
}
void setcolor(int fg,int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg*16+fg);
}
int bullet(int *x,int *y)
{
    gotoxy(*x,*y);
    printf(" ");
    gotoxy(*x,--*y);
    setcolor(2,0);
    printf("^");
}