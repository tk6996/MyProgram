#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long int x;
    int y=0,z,i=0;
    scanf("%llu",&x);
    while(x>0)
    {
     z=x%2; y=y+z*pow(2,i);
     x/=10;
     i++;
    }
    printf("%d",y);
}
