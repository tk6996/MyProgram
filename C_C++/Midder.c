#include <stdio.h>
int main(void)
{
    double a, b , c;
    scanf("%lf %lf %lf",&a,&b,&c);
    printf("%.2lf",(a > b) ? ((a < c) ? (a) : (b > c) ? b : c) : ((b < c) ? (b) : (a > c) ? a : c));
    return 0;
}