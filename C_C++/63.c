#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;
    double sum1,sum2,x;
    scanf("%d %d %d",&a,&b,&c);
    if(a!=0)
    {
     x=pow(b,2)-4*a*c;

    sum1=(-b-pow(x,0.5))/(2*a);
    sum2=(-b+pow(x,0.5))/(2*a);
    int temp;
    if(sum1>sum2)
    {
        temp=sum1;
        sum1=sum2;
        sum2=temp;
    }
    if(sum1<0&&sum2>0)
    printf("%.0lf,%.0lf",sum2,sum1);
    else printf("%.0lf,%.0lf",sum1,sum2);
        }
}
