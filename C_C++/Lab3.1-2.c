#include<stdio.h>
int main()
{
    int num,i;
    scanf("%d",&num);
    while(num>1)
    {
        for(i=2;i<=num;i++)
        {
            if(num%i==0){ printf("%d",i); num=num/i;break;}
        }
    if(num>1) printf(",");
    }
    return 0;
}