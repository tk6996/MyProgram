#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    c=a/b;
    if(a%b!=0) c++;
    printf("%d",c);
    return 0;
}
