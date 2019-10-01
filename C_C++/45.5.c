#include<stdio.h>
int factorial(int i)
{
    if(i<=1) return 1;
    else return i*factorial(i-1);
}

int main()
{
    int i,j,a,c,n,b=0,num[100000]={0},temp,p,q,modulo,m,k;
    scanf("%d",&a);
    scanf("%d",&n);
    scanf("%d",&modulo);
    c=a;
    while(c!=0)
    {
        num[b++]=c%10;
        c=c/10;
    }
    /*for(i=1;i<=b;i++)
    {
        printf("%d",num[b-i]);
    }*/
    for(k=2;k<=n;k++)
    {
    for(i=2;i<=k;i++)
    {
        q=0;
        for(j=0;j<b;j++)
        {
            p=num[j]*a + q;
            num[j]=p%10;
            q=p/10;
        }
        while(q!=0)
        {
            num[b]=q;
            q=q/10;
            b++;
        }
    }
    }
    for(i=0;i<b;i++)
    {
        m=num[i]%modulo;
        num[++i]+=m*10;
    }
    printf("%d",m);
    return 0;
}
