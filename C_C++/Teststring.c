#include<stdio.h>
int main()
{
    char a[100];
    int i=0;
    scanf("%s",a);
    while(a[i]!='\0')
    {
        if(a[i]>='A'&&a[i]<='Z')
        {
            printf("%c",a[i]);
        }
        i++;
    }
    
}