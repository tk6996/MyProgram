#include<stdio.h>
int main()
{
    int f=1,n;
    scanf("%d",&n);
    for(int i=n;i>0;i--)
    {
        f=f*i;
    }
    printf("%d",f);
}
