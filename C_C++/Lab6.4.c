#include<stdio.h>
#include<windows.h>
#include<conio.h>
int gotoxy(int, int );
int draw_ship(int,int);
int setcursor(boolean);
int setcolor(int,int);
int bullet(int*,int*,int*,int*);
int main()
{
    char ch='.',d='s';
    int x=38,y=20,bs[4][5]={{0}},i;
    boolean l,r,sb=0;
    setcursor(0);
    setcolor(2,4);
    draw_ship(x,y);
    do {
        if (kbhit()){
        ch=getch();
        switch(ch)
        {
        case 'a' : d='a';break;
        case 'd' : d='d';break;
        case 's' : d='s';break;
        case ' ' : sb=1;break;
        default : ;
        }
        fflush(stdin);
        }
        if(d=='a'&&x>0) {draw_ship(--x,y);}
        if(d=='d'&&x<=74) {draw_ship(++x,y);}
        if(sb==1)
        {
            for(i=0;i<5;i++)
            {
                if(bs[0][i]==0){bs[0][i]=1;break;}
            }
        }
        for(i=0;i<5;i++)
        {
        if(bs[0][i]==1)
            {
                if(bs[1][i]==0)
                {
                    bs[2][i]=x+2;bs[3][i]=y;
                }
                bullet(&bs[2][i],&bs[3][i],&bs[1][i],&bs[0][i]);
            }
        }
        sb=0;
    Sleep(100);
    }while (ch!='x');
    setcolor(7,0);
    return 0;
}
int gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , c);
    return 0;
}
int draw_ship(int x,int y)
{
    gotoxy(x,y); setcolor(2,4); printf("<-0->");setcolor(0,0); if(x<=74) printf(" ");
    if(x>0) gotoxy(--x,y); printf(" ");
    return 0;
}
int setcursor(boolean visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console,&lpCursor);
    return 0;
}
int setcolor(int fg,int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg*16+fg);
    return 0;
}
int bullet(int *x,int *y,int *stb,int *status)
{
    if(*stb!=0)
    {
        gotoxy(*x,*y);
        setcolor(0,0);
        printf(" ");
    }
    if(*y-1>=0)
    {
        gotoxy(*x,--*y);
        setcolor(2,0);
        printf("^");
        *stb=1;
    }
    else
    {
        *stb=0;
        *status=0;
    }
    return 0;
}