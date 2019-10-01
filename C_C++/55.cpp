#include<stdio.h>
int main()
{
    int n,q,m,a[1000],j=0;
    scanf("%d %d %d",&n,&q,&m);
    for(int i=0;i<q;i++)
    {
        a[i]=n+m*i;
        printf("%d",a[i]);
        j=j+a[i];
        if(i<q-1)
        printf("+");
    }
    printf(" = %d",j);
}
