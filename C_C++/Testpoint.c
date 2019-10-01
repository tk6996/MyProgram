#include<stdio.h>
int main()
{
    char *ptr;
    int i=0;
    scanf("%s",ptr);
    while(*ptr!='\0')
    {
        if(*ptr>='a'&&*ptr<='z') {printf("%c",*ptr+'A'-'a');}
        if(*ptr>='A'&&*ptr<='Z') {printf("%c",*ptr-'A'+'a');}
        *ptr++;
    }
}