#include<stdio.h>
#include<math.h>
int main()
{
    int N,i,j;
    scanf("%d",&N);
    for(i=-(N-1);i<=N-1;i++)
    {
        for(j=0;j<N;j++)
        {
            if(abs(i)-j>0) printf(" "); else printf("*");
        }
        printf("\n");
    }
    return 0;
}