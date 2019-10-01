#include<stdio.h>
int main()
{
    int i,n,q,x,p[100],a=0;
    scanf("%d %d",&n,&q);
    for(i=0;i<q;i++)
    {
        if(n==0) {p[i]=2+2*i;printf("%d",p[i]);}
        if(n==1) {p[i]=1+2*i;printf("%d",p[i]);}
        if(i<q-1) printf(" "); else printf("\n");
    }
    for(i=0;i<q;i++) a=a+p[i];
    printf("%d",a);
}
