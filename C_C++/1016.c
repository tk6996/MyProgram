#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
struct Position
{
    double x;
    double y;
};
typedef struct Position Position;
Position process(Position cur,char dir[BUFSIZ])
{
    int len = strlen(dir);
    int del_x=0,del_y=0;
    int direct = 0;
    char num[4] = {[0 ... 3] = 0};
    for (int i = 0; i < len; i++)
    {
        if(isdigit(dir[i])) num[i] = dir[i];
        else
        {
            switch (dir[i])
            {
            case 'N':del_y=1; break;
            case 'E':del_x=1; break;
            case 'S':del_y=-1;break;
            case 'W':del_x=-1;break;
            default:
                break;
            }
        }
    }
    int mulitplier = strtol(num,'\0',10);
    if(del_x ==0 ^ del_y == 0) cur.x += del_x*mulitplier,cur.y +=del_y*mulitplier;
    else cur.x += del_x/sqrt(2.0)*mulitplier,cur.y +=del_y/sqrt(2)*mulitplier;
    return cur;    
}
int main(void)
{
    Position current = {0,0};
    char buf[BUFSIZ]; 
    scanf("%s",buf);
    do
    {
        current = process(current,buf);
        scanf("%s",buf);    
    } while (buf[0] != '*');
    printf("%.3lf %.3lf\n%.3lf",current.x,current.y,sqrt(pow(current.x,2.0)+pow(current.y,2.0)));
    return 0;
}