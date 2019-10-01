#include<stdio.h>
int main()
{
    int n=0,i=0,j,b[10];
    char a[100];
    scanf("%s",a);
    while(a[i]!='\0')
    {
        n=n+a[i]-'0';
        i++;
    }
    printf("%s -> %d",a,n);
    while(n>=10)
    {
        i=0;
        while(n>0)
        {
            b[i]=n%10;
            n=n/10;
            i++;
        }
        for(j=0;j<i;j++)
        {
            n=n+b[j];
        }
        printf(" -> %d ",n);
    }
    return 0;
}