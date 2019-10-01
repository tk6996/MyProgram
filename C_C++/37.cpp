#include<stdio.h>
int main()
{
    int N,i,j,k;
    scanf("%d",&N);
        for(i=0;i<N-1;i++)
    {
        for(j=N-i;j>1;j--)
        {
            printf("-");
        }
        for(k=0;k<((i+1)*2)-1;k++) printf("+");
        for(j=N-i;j>1;j--)
        {
            printf("-");
        }
        printf("\n");
    }
/////////////////////////
            for(i=1;i<=(N*2)-1;i++)
            {
                if(i!=N)
                printf("+");else printf("*");
            }
            printf("\n");
/////////////////////////
            for(i=0;i<N-1;i++)
    {
        for(j=0;j<i+1;j++)
        {
            printf("-");
        }
        for(k=(N-1-i)*2;k>1;k--) printf("+");
        for(j=0;j<i+1;j++)
        {
            printf("-");
        }
        printf("\n");
    }
}
