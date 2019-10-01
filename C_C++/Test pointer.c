#include<stdio.h>
main()
{
    int a[2][2],*b;
    a[0][0]=8;
    a[0][1]=9;
    a[1][0]=10;
    a[1][1]=11;
    b=&a[0][0];
    printf("%d",*(b+3));
}
