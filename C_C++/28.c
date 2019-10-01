#include<stdio.h>
int main()
{
    int day,week,year;
    scanf("%d",&day);
    year=day/365;
    day=day-year*365;
    week=day/7;
    day=day-week*7;
    printf("YEAR:%d\n",year);
    printf("WEEK:%d\n",week);
    printf("DAY:%d",day);
}
