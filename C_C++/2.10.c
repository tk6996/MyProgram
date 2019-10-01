#include<stdio.h>
int main()
{
    int n;
    for(n=1;n<=12;n++)
    {
        if(n==1||n==12)
            printf("\t********************\n");
        else
            printf("\t*                  *\n");
    }
}
