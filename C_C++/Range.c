#include<stdio.h>
unsigned long long int f(long);
unsigned int num[10000000],count=0;
int main()
{
    int n,i,j,p,q,N,r;
    scanf("%d %d %d",&n,&p,&q);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            if(num[j]-num[i]>=p&&num[j]-num[i]<=q)
            {
                N=j-i-1;
                for(r=0;r<=N;r++)
                count=count+(f(N)/f(N-r)/f(r));
            }
        }
    }
    printf("%lu",count);
    return 0;
}
unsigned long long int f(long n)
{
    if(n<=1) return 1;
    else return (n*f(n-1));
}