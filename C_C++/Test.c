#include<stdio.h>
int main()
{
    int n,i,j,k;
    printf("Number of line => ");
    scanf("%d",&n);
    printf("\n");
    n=n*2;
    for(i=1;i<n;i+=2)
    {
    for(j=0;j<i;j+=2)
    {
    printf(" ");
    }
    for(k=n;k>i;k--)
    {
    printf("*");
    }
    printf("\n");
    }
}
