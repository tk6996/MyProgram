#include<stdio.h>
int relative_prime_check(int,int);
int main(int argv,char *argc[])
{
    int a,b;
    scanf("%d %d",&a,&b);
    if(relative_prime_check(a,b)==1)
    printf("relative prime");
    else
    printf("not relative prime");
    return 0;
}
int relative_prime_check(int a,int b)
{
    int i=2,k=0;
    while(i<=a)
    {
        if(a%i==0&&b%i==0) {k++;break;}
        i++;
    }
    if(k==0) return 1;
    else return 0;
}