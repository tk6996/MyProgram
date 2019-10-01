#include <stdio.h>
#include <math.h>
int main(void)
{
    float a,b,c;
    scanf("%f %f %f",&a,&b,&c);
    float s = (a + b + c)/2;
    float ans = sqrtf(s*(s-a)*(s-b)*(s-c));
    printf("Area of Triangle is %.2f",ans);
    return 0;
}