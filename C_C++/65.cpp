#include<stdio.h>
int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    int i,x[1000],j,k,temp;
    for(i=0;i<N;i++)
    {
        scanf("%d",&x[i]);
    }
    for(i=0;i<M;i++)
    {
        scanf("%d %d",&j,&k);
        temp=x[j-1];x[j-1]=x[k-1];x[k-1]=temp;
    }
    for(i=0;i<N;i++)
    {printf("%d ",x[i]);}
}