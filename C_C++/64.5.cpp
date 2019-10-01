#include<stdio.h>
int main()
{
    int i,j,a,c,n,b=0,num[100000]={0},temp,p,q;
    //scanf("%d",&a);
    scanf("%d",&n);
    a=2;c=a;
    while(c!=0)
    {
        num[b++]=c%10;
        c=c/10;
    }
    /*for(i=1;i<=b;i++)
    {
        printf("%d",num[b-i]);
    }*/
    for(i=2;i<=n;i++)
    {
        q=0;
        for(j=0;j<b;j++)
        {
            p=num[j]*a + q;
            num[j]=p%10;
            q=p/10;
        }
        while(q)
        {
            num[b]=q;
            q=q/10;
            b++;
        }
    }
    for(i=1;i<=b;i++)
    {
        printf("%d",num[b-i]);
    }
    return 0;
}