#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<pthread.h>
void gotoxy(int,int);
void *beep(void *);
void draw_ship(int,int);
void draw_bullet(int,int);
void clear_bullet(int,int);
void setcursor(boolean);
char cursor(int,int);
int Random(int,int);
void clear_object(int,int,int*,int*,int*);
pthread_t thread;
int main()
{
    srand(time(NULL));
    char ch='.';
    int x=38,y=20;
    int bx,by,i=0;
    int bullet = 0;
    int score=0;
    setcursor(0);
    draw_ship(x,y);
    gotoxy(70,0);
    printf("Score = ");
    do {
        while(i<20)
        {
        gotoxy(Random(10,70),Random(2,5));
        printf("*");i++;
        }
        gotoxy(78,0);
        printf("%2d",score);
        if (_kbhit()){
        ch=_getch();
        if(ch=='a') {if(x-1>6)draw_ship(--x,y);}
        if(ch=='d') {if(x+1<67)draw_ship(++x,y);}
        if(bullet!=1 && ch==' ') {bullet=1; bx=x+3; by=y-1;}
        fflush(stdin);
    }
    if (bullet==1) {
    clear_bullet(bx,by);
    if (by==2) { bullet=0;} else { if(cursor(bx,by-1)=='*') {clear_object(bx,by,&score,&i,&bullet);}else draw_bullet(bx,--by); }
    } 
    Sleep(100);
    } while (ch!='x');
    return 0;
}
void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
void draw_ship(int x,int y)
{
    gotoxy(x,y); printf(" <-0-> ");
}
void draw_bullet(int x,int y)
{
    gotoxy(x,y); 
    printf("%c",30);
    pthread_create(&thread, NULL, beep,(void *)0);
}
void clear_bullet(int x,int y)
{
    gotoxy(x,y); printf(" ");
}
int Random(int le,int ue)
{
    return rand()%(ue-le)+le;
}
void setcursor(boolean visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console,&lpCursor);
}
char cursor(int x, int y)
{
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    char buf[2]; COORD c = {x,y}; DWORD num_read;
    if(!ReadConsoleOutputCharacter(hStd,(LPTSTR)buf,1,c,(LPDWORD)&num_read) )
    return '\0';
    else
    return buf[0];
}
void clear_object(int bx,int by,int*score,int*i,int*bullet)
{
    gotoxy(bx,--by);
    printf(" ");
    pthread_create(&thread, NULL, beep,(void *)1);
    clear_bullet(bx,by);
    *score=*score+1;
    *i=*i-1;
    *bullet=0;
}
void *beep(void *threadid)
{
    long mode=(long)threadid;
    if(mode==0)
    Beep(700,100);
    else
    Beep(1000,100);
    pthread_exit(NULL);
}