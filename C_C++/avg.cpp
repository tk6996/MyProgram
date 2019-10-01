#include<stdio.h>
int main(void)
{
    double frist,second,sum,avg;
    printf("Enter number ");
    scanf("%lf",&frist);
    printf("Enter number ");
    scanf("%lf",&second);
    sum=frist+second;
    do
    {
        avg=(frist+second)/2.0;
        printf("avg of last two numbers %lf\n",avg);
        printf("Enter number ");
        frist=second;
        scanf("%lf",&second);
        sum+=second;
    } while (second<=avg);
    printf("---Data end ---\n");
    printf("all of sum %lf",sum);
    return 0;
}