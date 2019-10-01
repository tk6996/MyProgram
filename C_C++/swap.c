#include<stdio.h>
int swap(int*,int*);
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    swap(&a,&b);
    printf("%d %d",a,b);
    return 0;
}
int swap(int *x,int *y)
{
    *x^=*y;
    *y^=*x;
    *x^=*y;
    return 0;
}