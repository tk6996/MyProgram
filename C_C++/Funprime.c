#include<stdio.h>
int isPrime(int);
int main()
{
    int n;
    scanf("%d",&n);
    if(isPrime(n)==1) printf("Prime Number");
    else printf("Not Prime Number");
}
int isPrime(int x)
{
    if(x < 2) return 0;
    int i;
    for(i=2;i<x;i++)
    {
        if(x%i==0) return 0; 
    }
    return 1;
}