#include<stdio.h>
unsigned long long int f(long n);
int main()
{
    long n;
    scanf("%li",&n);
    printf("%llu",f(n));
    return 0;
}
unsigned long long int f(long n)
{
    if(n<=1) return 1;
    else return (n*f(n-1));
}
