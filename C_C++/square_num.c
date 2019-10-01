#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    for(int i=-(n-1);i<=n-1;i++)
    {
        for(int j=-(n-1);j<=n-1;j++)
        {
            printf("%d",n-(abs(i)>abs(j) ? abs(i) : abs(j)));
        }
        printf("\n");
    }
    return 0;
}
