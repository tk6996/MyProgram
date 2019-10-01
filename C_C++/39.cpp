#include<stdio.h>
int main()
{
    int n,x[300],f=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&x[i]);
    if(x[0]>=80) f++;
    for(int i=1;i<n;i++)
    {
        if(x[i]>=80||(x[i]>=20&&x[i]-x[i-1]>=10)) f++;
    }
    printf("%d",f);
}
