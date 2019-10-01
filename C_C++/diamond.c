#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,x,y,j,k;
    scanf("%d",&n);
    {
        for(y=-(n-1);y<=n-1;y++)
        {
            k=1;
            for(x=-(n-1);x<=n-1;x++)
            {
                if(abs(x)+abs(y)<=n-1) {if(x<0) printf("%d",k++); else if(x>=0) printf("%d",k--); }
                else printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}