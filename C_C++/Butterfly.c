#include<stdio.h>
int main()
{
    int n,i,j,d;
    scanf("%d",&n);
    for(i=1;i<=2*n-1;i++)
    {
        for(j=1;j<=2*n-1;j++)
        {
            if((i>=j&&i<=n)||(i<=j&&i>n)) printf("*"); 
            else if((2*n-i<=j&&i<=n)||(2*n-i>=j&&i>n)) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}