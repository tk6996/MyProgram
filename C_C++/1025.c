#include <stdio.h>
unsigned int lcm(unsigned int a,unsigned int b)
{
    unsigned int val = 1UL;
    unsigned int div = (a < b) ? a : b;
    while (div <= a && div <= b && div > 1)
    {
        if(a%div == 0 && b%div == 0)
        {
            val*=div;
            a/=div;
            b/=div;
        }
        else
            --div;
    }
    return val*a*b;
}
int main(void)
{
    unsigned int a,b;
    unsigned int count;
    scanf("%u",&count);
    scanf("%u",&a);
    for (unsigned int i = 1; i < count; i++)
    {
        scanf("%u",&b);
        a = lcm(a,b);
    }
    printf("%u",a);
}