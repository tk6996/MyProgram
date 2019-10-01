#include<stdio.h>
int main()
{
    char cha[1];
    int i,n,j;
    scanf("%c %d",&cha,&n);
    for(i=1;i<n/2;i++)
    {
        for(j=1;j<=n;j++)
        {
        if(i<=n/2){if(j<=i&&j<=n/2) printf("%c",cha[0]);else if(j<=n-i)printf("."); else printf("%c",cha[0]);}
        }
        printf("\n");
    }
    for(i=n/2;i>=1;i--)
    {
        for(j=1;j<=n;j++)
        {
        if(i<=n/2){if(j<=i&&j<=n/2) printf("%c",cha[0]);else if(j<=n-i)printf("."); else printf("%c",cha[0]);}
        }
        printf("\n");
    }
}
