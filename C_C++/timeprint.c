#include <windows.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int i,j,a[100],m=0,count=0;
    for(i=1;i<=100;i++)
    {
        for(j=i+1;j<=100;j++)
        {
             m=max(a[i-1]*a[j-1],m);
             count=++count;
        }
    }
    printf("%d",count);
    return 0;
}