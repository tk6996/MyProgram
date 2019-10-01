#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
int gotoxy(int, int );
int setcursor(boolean);
int basepong(int,int,int*);
int erasebase(int,int);
int pongmove(int*,int*,int*,int*);
int w,h;
int main(int argc,char*argv[])
{
    srand(time(NULL));
    scanf("%d %d",&w,&h);
    int d=0,xdirectionbase=rand()%w+1,ydirectionbase=h,i,j,deathcount=0,xpong,ypong,xpongdirection,ypongdirection=0,base[3];
    boolean death=0;
    char button='.';
    system("cls");
    setcursor(0);
    for(i=0;i<=h+1;i++)
    {
        for(j=0;j<=w+1;j++)
        {
            if((i==0||i==h+1)&&(j==0||j==w+1))
            {
                if(i==0&&j==0) printf("%c",201);
                if(i==0&&j==w+1) printf("%c",187);
                if(i==h+1&&j==0) printf("%c",200);
                if(i==h+1&&j==w+1) printf("%c",188);
            }
            else if(i==0||i==h+1)
            {
                printf("%c",205);
            }
            else if(j==0||j==w+1)
            {
                printf("%c",186);
            }
            else printf(" ");
        }
        printf("\n");
    }
    xpong=rand()%w+1;
    ypong=rand()%3+1;
    xpongdirection=rand()%2;
    gotoxy(xpong,ypong);printf("*");
    basepong(xdirectionbase,ydirectionbase,base);
    do
    {
    if(_kbhit())
    {
        button=getch();
        switch(button)
        {
            case 'a' : if(xdirectionbase>=2) {erasebase(xdirectionbase,ydirectionbase);--xdirectionbase;}break;
            case 'd' : if(xdirectionbase<=w-3) {erasebase(xdirectionbase,ydirectionbase); ++xdirectionbase;}break;
            defalut:;
        }
        fflush(stdin);
        basepong(xdirectionbase,ydirectionbase,base);
    }
    if(ypong==h-1)
    {
        
        
    }
    pongmove(&xpong,&ypong,&xpongdirection,&ypongdirection);
    Sleep(100);
    }while(death==0);


    return 0;
}

int gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , c);
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
int basepong(int x,int y,int *base)
{
        int i,p=0;
        gotoxy(x,y);
        for(i=1;i<=w;i++)
        {
            if(i-x>=0&&i-x<=2)
            {base[p]=i;p++;}
        }
        gotoxy(base[0],h);
        printf("%c%c%c",178,178,178);
        /*gotoxy(0,h+2);
        printf("");
        gotoxy(base[0],h+2);
        printf("%d%d%d",base[0],base[1],base[2]);*/
        return 0;
}
int erasebase(int x,int y)
{
    gotoxy(x,y);
    printf("   ");
    return 0;
}    
int pongmove(int *x,int *y,int *dx,int *dy)
{
    gotoxy(*x,*y); printf(" ");
    if(*x==1)  *dx=1;
    if(*x==w)  *dx=0;
    if(*y==1)  *dy=0;
    if(*y==h)  *dy=1;
    if(*dx==1) *x=*x+1;
    if(*dx==0) *x=*x-1;
    if(*dy==0) *y=*y+1;
    if(*dy==1) *y=*y-1;
    gotoxy(*x,*y);printf("*");
    return 0;
}