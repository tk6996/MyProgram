#include<stdio.h>

int main()
{
    int x[3],i,j,k;
    for(i=0;i<3;i++)
    scanf("%d",&x[i]);
    for(k=3;k>0;--k)
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
    if(x[2]>=x[1]+x[0]) printf("Triangle is not valid.");
    else printf("Triangle is valid.");


}
