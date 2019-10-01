#include<stdio.h>
void halfhigh(int);
void halflow(int);
int main()
{
    int n;
    scanf("%d",&n);
    halfhigh(n);
    halflow(n);
}
void halflow(int n)
{
    int i,j;
        for(i=1;i<=n*2-1;i++)
    {
        for(j=1;j<=(n-1)*2;j++)
        {
            if(j<i) printf(".");
            if(j==i)printf("*");
            if(j>i) printf("-");
        }

        if(i==1||i==n*2-1)printf("*");else printf("-");

                for(j=1;j<=(n-1)*2;j++)
        {
            if(j>(n-1)*2-i+1) printf(".");
            if(j==(n-1)*2-i+1)  printf("*");
            if(j<(n-1)*2-i+1) printf("-");
        }
        printf("\n");
    }
}
void halfhigh(int n)
{
    int i,j;
    for(i=1;i<n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j<n-i+1) printf(".");
            if(j==n-i+1) printf("*");
            if(j>n-i+1) printf("-");
        }
        for(j=1;j<=n-2;j++)
        {
            if(j>i-1) printf(".");
            if(j==i-1) printf("*");
            if(j<i-1) printf("-");
        }
        printf(".");
        for(j=1;j<=n-2;j++)
        {
            if(j<n-i) printf(".");
            if(j==n-i) printf("*");
            if(j>n-i) printf("-");
        }
        for(j=1;j<=n;j++)
        {
            if(j>i) printf(".");
            if(j==i) printf("*");
            if(j<i) printf("-");
        }
        printf("\n");
    }
}
