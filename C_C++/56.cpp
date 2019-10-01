#include<stdio.h>
int main()
{
    int N,Q,i,j,a[2][100000]={{0}},b[2][10000];
    scanf("%d %d",&N,&Q);
    for(i=0;i<N;i++)
    {
        scanf("%d",&a[0][i]);
    }
    for(i=0;i<Q;i++)
    {
        scanf("%d %d",&b[0][i],&b[1][i]);
    }
    for(i=0;i<Q;i++)
    {
        for(j=0;j<N;j++)
        {
            if(a[0][j]>=b[0][i]&&a[0][j]<=b[1][i]) a[1][i]++;
        }
    }
    for(i=0;i<N;i++)
    {
        printf("%d\n",a[1][i]);
    }
    return 0;
}