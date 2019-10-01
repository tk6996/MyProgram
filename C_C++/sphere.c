#include <stdio.h>
float shpereVoulume(float r)
{
    const float PI = 3.14159265358979323846;
    return (4.0f/3.0f)*PI*r*r*r;
}
int main(void)
{
    float a , b;
    scanf("%f %f",&a,&b);
    float sa = shpereVoulume(a/2),sb = shpereVoulume(b/2);
    printf("%.3f",(sa > sb) ? sa-sb : sb-sa);
    return 0;
}