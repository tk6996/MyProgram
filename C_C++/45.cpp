#include<stdio.h>
#include<math.h>
int factorial(int);
int main()
{
    unsigned long int a,b,c,i,d;
    scanf("%d %d %d",&a,&b,&c);
    for(i=1;i<=b;i++)
    {
        d=pow(a,i);
        printf("%li ^ %li mod %li = %li\n",a,i,c,d%c);
    }
   
}
int factorial(int i)
{
    if(i<=1) return 1;
    else return i*factorial(i-1);
}
