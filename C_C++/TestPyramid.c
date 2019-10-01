#include<stdio.h>
main()
{
    float m,n,i,j,k;
    printf("Pyramid mode 1 1--->n\n");
    printf("Pyramid mode 2 n--->1\n");
    printf("Select mode : ");
    scanf("%f",&m);
    if(m==1||m==2){
    printf("Enter Number Line for Pyramid : ");
    scanf("%f",&n);
    printf("\n\n");
    i=n;
    if(m==1){
    while(i>0)
        {
        for(j=i-1;j>0;j--)
            {
            printf(" ");
            }
        for(k=0;k<=n-i;k=k+0.5)
            {
            printf("*");
            }
        i=i-1;
        printf("\n");
        }
        }
        if(m==2){
    while(i>0)
        {
        for(k=0;k<n-i;k++)
            {
            printf(" ");
            }
        for(j=i-1;j>=0;j=j-0.5)
            {
            printf("*");
            }
        i=i-1;
        printf("\n");
        }
        }
        }
}
