#include<stdio.h>
int main()
{
    int x[10000],n,i;
    n=3;
    for(i=0;i<n;i++)
    scanf("%d",&x[i]);
    int temp,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        if(x[j]>x[j+1])
            {temp=x[j]; x[j]=x[j+1]; x[j+1]=temp;}
    }
    printf("%d",x[1]);
}


