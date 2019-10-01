#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef union Binary
    {
        unsigned long long bit_64;
        double floating_point
    }bi;
void print_binary(bi A)
{
    char format[65]={0};  
    for(int i=63;i>=0;i--)
    {
        format[i]='0'+ A.bit_64%2;
        A.bit_64/=2;
    }
    printf("%s",format);
}
int main(int argc, char const *argv[])
{
    
    bi  t;
    t.floating_point=1.0f+(1.0f/9.0f);
    print_binary(t);
    printf("\n%lf",t.floating_point);
}
