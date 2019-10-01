#include<stdio.h>
#include<math.h>
int main()
{
    int x[10][2]={0},i,n;
    printf("Program Count Number 10 Number\n");
    for(i=0;i<=9;i++)
    {
        printf("Enter Number %d: ",i+1);
        scanf("%d",&x[i][0]);
        for(n=0;n<=i;n++)
            {
        if(x[i][0]==x[n][0])
        {
            x[n][1]++;break;
        }}
        if(x[n][1]==0)
            {
                x[i][1]++;
            }

    }
    printf("Result\n");
    for(n=0;n<i;n++)
    if(x[n][1]!=0)
    printf("%d\t%d\n",x[n][0],x[n][1]);
}
