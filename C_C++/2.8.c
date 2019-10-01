#include<stdio.h>
int main()
{
    int n,i;
    float f,j,k;
    i=j=k=0;
    for(n=1;n<=10;n++)
    {
        printf("Enter number %d : ",n);
        scanf("%d",&i);
        f=f+i;
        if(i>j)
            j=i;
        if(i<k)
            k=i;
    }
    printf("\nAverage number = %.2f",f/10);
    printf("\nMax number = %.2f",j);
    printf("\nMin number = %.2f",k);
}
