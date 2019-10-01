#include<stdio.h>
int main()
{
    int n,m;
    n=m=0;
    while (n!=-999)
    {
    printf("Enter number :  ");
    scanf("%d",&n);
    if(n!=-999)
    m=m+n;
    }
    printf("\nSum of all numbers = %d",m);
}
