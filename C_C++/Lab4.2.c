#include<stdio.h>
int main()
{
    int n,i,x;
    for(n=1;n<=10000;n++)
    {
        x=0;
        for(i=1;i<n;i++)
        {
            if(n%i==0)
            {
                x=x+i;
            }
        }
        if(n==x) printf("%d\t",n);
    }
    return 0;
}