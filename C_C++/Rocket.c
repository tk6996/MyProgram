#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
int gotoxy(int,int);
int setcursor(bool);
int setcolor(int,int);
int drawship(int,int);
int eraseship(int,int);
char Input_Keyborad();
bool Scan_Keyborad(char);
int moverocket(int*,int*);
char cursor(int,int);
int setup_bullet_status();
int bulletshoot(int,int);
int bulletmove();
int clearbullet(int,int,int);
int random(int,int);
int setup_star_status();
int printstar();
int bullet_crash_star(int);
int starmove();
int Scorecheck(int);
int Time_game();
void *beep_beep(void *);
int Menu_Game();
int set_up_borad();
int set_borad();
pthread_t beep;
struct bullet
{
    int posx,posy,status;
};
struct bullet B[5];
int star[3][20],score=0,statusbeep=0,Ender=1,Time_start;
char move='s';
bool bulletstatus=0;
int main()
{
    ///////////// Variable /////////////
    int xship=35,yship=22,starfalltime=1,level=5;
    char In_Key,End=' ';
    bool exitstatus=0;
    /////////////Setup Game/////////////
    system("cls");
    setcursor(0);
    srand(time(NULL));
    set_up_borad();
    if(0){
    Restart : system("cls");
    score=0;Ender=1;move='s';statusbeep=0;bulletstatus=0;xship=35;yship=22;starfalltime=1;level=5;End=' ';exitstatus=0;}
    set_borad();
    setup_bullet_status();
    setup_star_status();
    drawship(xship,yship);
    printstar();
    pthread_create(&beep,NULL,beep_beep, (void *)0);
    gotoxy(64,0); printf("Score :%9d",score);
    Time_start=clock()/1000;
    gotoxy(64,1); printf("Time  :%9d",clock()/1000-Time_start);
    ////////////Game Running////////////
    while(exitstatus==0)
    {
        if(level>1) level=5-(clock()/1000-Time_start)/30;
        Time_game();
        In_Key='.';
        starfalltime++;
        printstar();
        if(_kbhit()) In_Key=Input_Keyborad();
        exitstatus=Scan_Keyborad(In_Key);
        if(moverocket(&xship,&yship)==1){Beep(1300,300);exitstatus=1;}
        if(bulletstatus==1){bulletshoot(xship,yship);}
        if(starfalltime%level==0)if(starmove()){Beep(1300,300);exitstatus=1;}
        if(starfalltime>60) starfalltime=1;
        bulletmove();
        Sleep(100);
    }
    ////////////Finish Game ////////////
    Ender=0;
    system("cls");
    if(Menu_Game()==1) goto Restart;
    return 0;
}
int gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , c);
    return 0;
}
int setcursor(bool visible)
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
int drawship(int x,int y)
{
    gotoxy(x,y);
    setcolor(12,0);
    printf("<=");
    setcolor(14,0);
    printf("|");
    setcolor(2,0);
    printf("+");
    setcolor(14,0);
    printf("|");
    setcolor(12,0);
    printf("=>");
     setcolor(15,0);
    return 0;
}
int eraseship(int x,int y)
{
    gotoxy(x,y);
    printf("       ");
    return 0;
}
char Input_Keyborad()
{
    char c;
    c=getch();
    fflush(stdin);
    return c;
}
bool Scan_Keyborad(char c)
{
    bool exitstatus=0;
    switch(c)
    {
        case 'a' : move='a';break;
        case 'd' : move='d';break;
        case 's' : move='s';break;
        case ' ' : bulletstatus=1;break;
        case 'x' : exitstatus=1;break;
        default:;
    }
    return exitstatus;
}
int moverocket(int *xship,int *yship)
{
    int e=0;
    if(move=='a'&& *xship>0+10)if(cursor(*xship-1,*yship)!='*'){eraseship(*xship,*yship);drawship(--(*xship),*yship);} else e=1;
    if(move=='d'&& *xship<74-10)if(cursor(*xship+7,*yship)!='*'){eraseship(*xship,*yship);drawship(++(*xship),*yship);} else e=1;
    if (e==0) return 0;
    else {return 1;}
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
int setup_bullet_status()
{
    int i;
    for(i=0;i<5;i++) B[i].status=0;
    return 0;
}
int bulletshoot(int x,int y)
{
    int i,j,k=0;
    for(j=0;j<20;j++)
    {
        if(x+3==star[0][j]&&y-1==star[1][j])
        {
            gotoxy(x+3,y-1);printf(" ");Scorecheck(10);star[2][j]=0;k=1;statusbeep=1;
        }
    }
    if(k==0)
    for(i=0;i<5;i++)
        {
        if(B[i].status==0){B[i].status=1;B[i].posx=x+3;B[i].posy=y-1;gotoxy(B[i].posx,B[i].posy);setcolor(9,0);printf("%c",30);setcolor(15,0);break;}
        }
    bulletstatus=0;
    return 0;
}
int bulletmove()
{
    int i;
    for(i=0;i<5;i++)
    {
        if(B[i].status==1){
            gotoxy(B[i].posx,B[i].posy--);printf(" ");
            if(cursor(B[i].posx,B[i].posy)=='*') bullet_crash_star(i);
            else if(B[i].posy>2)
            {gotoxy(B[i].posx,B[i].posy);setcolor(9,0);printf("%c",30);setcolor(15,0);   }
            else
            clearbullet(B[i].posx,B[i].posy+1,i);
            }
    }
    return 0;
}
int clearbullet(int x,int y,int i)
{
    gotoxy(x,y);
    printf(" ");
    B[i].status=0;
    return 0;
}
int random(int Upper_Boundary,int Lower_Boundary)
{
    return rand()%(Upper_Boundary-Lower_Boundary)+Lower_Boundary;
}
int setup_star_status()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<20;j++)
        star[i][j]=0;
    }
    return 0;
}
int printstar()
{
    int i,j;
    for(i=0;i<20;i++)
    {
        if(star[2][i]==0)
        {
        restart_random:
        star[0][i]=random(70,10);
        star[1][i]=random(6,3);
        for(j=0;j<20;j++)
        {
            if(star[0][i]==star[0][j]&&star[1][j]==star[1][j]&&i!=j)
            {
                goto restart_random;
            }
        }
        gotoxy(star[0][i],star[1][i]);
        setcolor(14,0);
        printf("*");
        setcolor(15,0);
        star[2][i]=1;
        }
    }
    return 0;
}
int bullet_crash_star(int i)
{
    int j;
    for(j=0;j<20;j++)
    {
        if(star[0][j]==B[i].posx&&star[1][j]==B[i].posy)
        {
            clearbullet(B[i].posx,B[i].posy+1,i);
            gotoxy(star[0][j],star[1][j]); printf(" ");
            statusbeep=1;
            Scorecheck(10);star[2][j]=0;
        }
    }
    return 0;
}
int starmove()
{
    int i,j,e=0;
    for(i=0;i<20;i++)
    if(star[2][i]==1)
        {
            gotoxy(star[0][i],star[1][i]);
            printf(" ");
            gotoxy(star[0][i],++star[1][i]);
            if(cursor(star[0][i],star[1][i])=='<'||cursor(star[0][i],star[1][i])=='='
            ||cursor(star[0][i],star[1][i])=='|'||cursor(star[0][i],star[1][i])=='+'
            ||cursor(star[0][i],star[1][i])=='>'){e=1;}
            for(j=0;j<5;j++)
            {
                if(B[j].posx==star[0][i]&&B[j].posy==star[1][i])
                {
                    clearbullet(B[j].posx,B[j].posy,j);
                    statusbeep=1;
                    star[2][i]=0;Scorecheck(10);goto skip_print_star;
                }
            }
            setcolor(14,0);
            printf("*");
            setcolor(15,0);
            skip_print_star :
            if(star[1][i]>=23) {gotoxy(star[0][i],star[1][i]); printf(" "); star[2][i]=0;}
        }
    if(e==1) {return 1;}
    else return 0;
}
void *beep_beep(void *status_sound)
{
    int i;
    while(Ender)
    {
    if(statusbeep==1) {Beep(1000,100);statusbeep=0;}
        if(statusbeep==0)for(i=0;i<5;i++)
        {
            if(B[i].status==1){Sleep(50);Beep(800,100);break;}
        }
    }
    pthread_exit(NULL);
}
int Scorecheck(int i)
{
    score=score+i;
    gotoxy(71,0);printf("%9d",score);
    return 0;
}
int Time_game()
{
    gotoxy(71,1);printf("%9d",clock()/1000-Time_start);
    return 0;
}
int Menu_Game()
{
    int r=0;
    char i=' ';
    gotoxy(30,10);printf("Your Score :%9d",score);
    gotoxy(30,11);printf("Your Time  :%9d",clock()/1000-Time_start);
    gotoxy(33,13);printf("   Create By   ");
    gotoxy(33,14);printf("Watcharin Kanha");
    gotoxy(33,15);printf("   61010960    ");
    gotoxy(32,17);printf("Press x for Exit.");
    gotoxy(29,18);printf("Press Enter for Restart");
    while(i!='x'&&r==0){i=getch();if(i==13)r=1; }
    return r;
}
int set_up_borad()
{
    int i;
    char j;
    setcolor(15,0);
    gotoxy(11,5);printf(" ***  ****   ***   **** *****     ***  *   * ***** ****");
    gotoxy(11,6);printf("*     *   * *   * *     *        *     *   *   *   *   *");
    gotoxy(11,7);printf(" ***  ****  ***** *     *****     ***  *****   *   ****");
    gotoxy(11,8);printf("    * *     *   * *     *            * *   *   *   *");
    gotoxy(11,9);printf(" ***  *     *   *  **** *****     ***  *   * ***** *");
    gotoxy(27,12);printf("Press Enter for Play.");
    gotoxy(20,14);printf("a : move left     Spece Bar : shoot      ");
    gotoxy(20,15);printf("d : move right       x      : finish game");
    gotoxy(20,16);printf("s : stop move");
    while(j!=13){j=getch();}
    return 0;
}
int set_borad()
{
    int i;
    system("cls");
    gotoxy(10,0);printf("|a : move left     |d : move right |s : stop move |");
    gotoxy(10,1);printf("|Spece Bar : shoot |x : finish game|");
    setcolor(7,0);
    gotoxy(9,2);printf("%c",201);for(i=0;i<=60;i++){printf("%c",205);} printf("%c",187);
    for(i=3;i<=23;i++){gotoxy(9,i);printf("%c",186);gotoxy(71,i);printf("%c",186);}
    gotoxy(9,24);printf("%c",200);for(i=0;i<=60;i++){printf("%c",205);} printf("%c",188);
    setcolor(15,0);
    return 0;
}