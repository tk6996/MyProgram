#include<stdio.h>
int main()
{
    int i,j,z=0,x[5],y[5],temp;
    for(i=0;i<5;i++)
    scanf("%d",&x[i]);
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        if(x[j]>x[j+1]){temp=x[j];x[j]=x[j+1];x[j+1]=temp;}
    }
    //printf("%d %d %d %d %d",x[0],x[1],x[2],x[3],x[4]);
    for(i=0;i<5;i++)
        if(i%2==0) y[i]=x[i]*(-1);else y[i]=x[i];
    //printf("%d %d %d %d %d",x[0],x[1],x[2],x[3],x[4]);
    for(i=0;i<5;i++)
    z=z+y[i];
    for(i=0;i<5;i++)
    {
        if(z==y[i]) printf("%d",x[i]);
    }
}
