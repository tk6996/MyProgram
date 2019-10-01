#include <stdio.h>
int main(void)
{
    auto int n,i,j;
    printf("Enter the number : ");
    scanf("%d",&n);
    for(i=0,j=0;i<n+n-2;i++,j++,(j==n) ? j=0,i-=(n-1),printf("\n") : 1)
    {
        printf("%c",'a'+i);
    }
    printf("%c",'a'+i);
    return 0;
}