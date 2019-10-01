#include<stdio.h>
int main()
{
    int d,day,month,year;
    scanf("%d",&d);
    day=d/20;
    if(d%20!=0) day+=1;
    year=day/365;
    day=day-year*365;
    month=day/30;
    day=day-month*30;
    printf("%d year, ",year);
    printf("%d month, ",month);
    printf("%d day ",day);
}
