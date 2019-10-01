#include<stdio.h>
int main()
{
    int n,a[100],b[100],p,d=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        p=a[i]*a[i+1]; d=d+p;
    }
    printf("%d",d);
}
