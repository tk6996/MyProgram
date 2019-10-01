#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=12;i++)
    {
        if(i<10)
        printf("%d x  %d = ",n,i);
        else printf("%d x %d = ",n,i);
        if(n*i<10)
            printf("  %d",n*i);else
        if(n*i<100)
            printf(" %d",n*i);
        else
            printf("%d",n*i);
        printf("\n");
    }
}
