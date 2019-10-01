#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    int d;
    char str[100];
    scanf("%[^\n]s",str);
    d=strlen(str);
    printf("%d",d);
}
