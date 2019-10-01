#include<stdio.h>
int main()
{
    int i=0,x,y,xt=0;
    scanf("%d %d",&x,&y);
    while(xt<y)
    {
        i++;
        xt=x*i;
    }
    printf("%d",i);
}
