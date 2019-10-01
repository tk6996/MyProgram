#include<stdio.h>
void swap (int* ,int*);
int main()
{
    int a=5,b=3;
    swap(&a,&b);
    printf("%d %d",a,b);
    return 0;
}
void swap (int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}