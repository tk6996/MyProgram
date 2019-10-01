#include<stdio.h>
int main()
{
    int a,b,c;
    for(a=1;a<=1000;a++)
    {
        for(b=1;b<=a;b++)
        {
            for(c=1;c<=b;c++)
            {
                if(a+b+c==1000) if((a*a==b*b+c*c)||(b*b==a*a+c*c)||(c*c==a*a+b*b)) printf("%d %d %d",a,b,c);
            }
        }
    }
    return 0;
}