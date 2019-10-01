#include<stdio.h>
void main()
{
    int n[10],i;
    for(i=0;i<=9;i++)
        n[i]=i+1;
    printf("%s%13s\n","Element","Value");
    for(i=0;i<=9;i++)
    printf("[%2d]%14d\n",i,n[i]);
}
