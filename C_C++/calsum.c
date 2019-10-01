#include<stdio.h>
#include<stdlib.h>
int main()
{
    for(int i=0;i<10000;i++)
    {if(rand()%2)printf("-");printf("%d,",rand()%10000);}
    return 0;
}