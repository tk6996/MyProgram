#include<stdio.h>
int main()
{
    int n,i,j=0,d;
    scanf("%d",&n);

    for(i=1;i<=n*n;i++)
    {
        if(n%2==0&&((i/n)%2==1)||(i%n==0))d=1; else d=0;
        if(i%2+d==1) {printf("*");}
        else {printf("-");}
        j++;
        if(j==n) {printf("\n");j=0;}
    }
    return 0;
}
