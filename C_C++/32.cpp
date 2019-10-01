#include<stdio.h>
int main()
{
    int x,y,z;
    scanf("%d",&x);
    y=x/10;
    z=x-y*10;
    if(z<0) z=z*(-1);
    printf("%d",z);
}
