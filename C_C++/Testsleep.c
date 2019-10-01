#include<stdio.h>
#include<windows.h>
void delay(int ms)
{
    Sleep(ms);
}
int main()
{
    int i;
    for(i=0;i<10;i++)
    {
        printf(" %d ",i);
        delay(1000);
    }
    return 0;
}