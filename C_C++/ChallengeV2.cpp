#include<stdio.h>
#include<math.h>
int min (int x,int y){if(x<y) return x; else return y;}
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=-n;i<=n;i++)
    {
        for(j=-n;j<=n;j++)
        {
            printf("%d",min(n-abs(j),n-abs(i)));
        }
        printf("\n");
    }
}