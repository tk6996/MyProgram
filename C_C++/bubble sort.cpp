#include<stdio.h>

int main()
{
    int x[10],i,j,k;
    for(i=0;i<10;i++)
    scanf("%d",&x[i]);
    for(k=10;k>0;--k)
    {
            for(i=0;i<k;i++)
    {
        if(x[i]>x[i+1])
        {
            j=x[i+1];
            x[i+1]=x[i];
            x[i]=j;
        }
    }
    }
    for(i=0;i<10;i++)
    {
        printf("%d",x[i]);
    }
}
