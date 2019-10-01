#include<stdio.h>
#include<math.h>
int min (int x,int y){if(x<y) return x; else return y;}
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<=n*2;i++)
    {
        for(j=0;j<=n*2;j++)
        {
            if((j<=n&&j>=n-i&&i<=n)||(j>n&&j<=n+i&&i<=n)||(i-n<=j&&j>=n-i&&j<=n)||(j<=n*3-i&&j>n&&i>n)) printf("%d",min(n-abs(n-j),n-abs(n-i)));
            else printf(" ");
        }
        printf("\n");
    }
}